#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include "bin_heap.h"
#include "huffman.h"
#include "image.h"

using namespace std;

matrix<string> reduce_img_mat(matrix<double> & original, int nlevels) {
    /* This function reduces the number of possible values that elements of the
    input matrix can take to nlevels. It is used to reduce the number of colors
    or luminance levels in an image. */

    int dim[2] = {original.nrow(), original.ncol()};
    matrix<string> out (dim);

    /**********************************/
    /******* COMPLETE CODE HERE *******/

    // Change the value of each element (pixel) in the matrix to the nearest
    // allowed "level".
    for (int i=0; i < dim[0]; i++) {
        for (int j=0; j < dim[1]; j++) {
            int pixel_val = original[i][j] * (nlevels - 1);
            out[i][j] = img::int2string(pixel_val);
        }
    }
    return out;
}

map<string, huffman::TreeNode> huffman_code_tree(
        vector<string> alphabet, map<string, double> frequencies) {
    /* Create a Huffman prefix-free encoding tree with lower frequency letters
    in the input alphabet at lower leaves in the tree. The tree will
    subsequently be used to generate efficient binary codewords for each
    letter. */

    // Create priority queue using a binary heap holding first the alphabet,
    // then their parent nodes in the encoding tree, with frequencies as keys.
    // Also create a map to hold all of the nodes in the tree, which will be
    // returned at the end of this function. Initially fill this map with the
    // leaf nodes holding the alphabet letters.
    BinaryHeap<string, double> Q;
    map<string, huffman::TreeNode> nodes;

    /**********************************/
    /******* COMPLETE CODE HERE *******/

    // Initialize the Q and nodes map, filling the latter first with the leaf
    // nodes holding the alphabet letters.
    for (int i=0; i < alphabet.size(); i++) {
        huffman::TreeNode node (alphabet[i], frequencies[alphabet[i]]);
        nodes.insert(pair<string, huffman::TreeNode> (alphabet[i], node));
        Q.insert(alphabet[i], frequencies[alphabet[i]]);
    }

    // Build binary tree for encoding, keeping it full as nodes are joined. The
    // nodes should all end up stored in the 'nodes' map created above.
    while (Q.size() > 1) {
        // Get two lowest frequency elements from queue
        string a = Q.pop_min();
        string b = Q.pop_min();

        // Create a parent node for these two letters
        string parent_label = nodes[a].label + "_" + nodes[b].label;
        double parent_freq = nodes[a].freq + nodes[b].freq;
        huffman::TreeNode ab (parent_label, parent_freq);
        ab.leaf = false; // Any parent node will not be a leaf
        ab.left = a; // left child
        ab.right = b; // right child
        nodes[a].parent = ab.label;
        nodes[b].parent = ab.label;
        nodes.insert(pair<string, huffman::TreeNode> (ab.label, ab));
        Q.insert(ab.label, ab.freq);
    }
    // The final element in the queue is the root node. Set its parent to
    // itself (i.e., the parent string in the node should equal the nodes
    // label)to signify it is the root, and insert it in the node container.
    huffman::TreeNode root = nodes[Q.pop_min()];
    root.parent = root.label;
    nodes[root.label] = root;

    // Return the container holding the tree
    return nodes;
}

map<string, string> get_code_map(map<string, huffman::TreeNode> & tree,
                                 vector<string> & alphabet) {
    /* Generate a code map specifying the Huffman encoding of the alphabet,
    using the tree constructed and returned by huffman_code_tree(). The map
    contains each codeword, keyed by its corresponding alphabet symbol. */

    map<string, string> code_map;  // codewords are strings of bits, "0" & "1"
    
    /**********************************/
    /******* COMPLETE CODE HERE *******/

    // Using the encoding tree, create codewords where left branches add a "0"
    // bit and right branches add a "1" bit.
    for (int i=0; i < alphabet.size(); i++) {
        string code = "";
        string node = alphabet[i];
        string parent = tree[node].parent;
        while (parent != node) { // while (current node is not the root)
            // Add a 0/1 for left/right children of the current node
            if (node == tree[parent].left) {
                code += "0";
            } else {
                code += "1";
            }

            // Move up to the parent node
            node = parent;
            parent = tree[node].parent;
        }
        code_map.insert(pair<string, string> (alphabet[i], code));
    }
    return code_map;
}

double basic_code_length(map<string, double> & frequencies) {
    /* Calculate the "message length" using the frequencies of each symbol in
    the alphabet and uniform-length codewords (e.g., 4 bits per symbol for a
    16-symbol alphabet). */

    // Get alphabet from frequency map keys
    vector<string> alphabet;
    for (map<string, double>::iterator it=frequencies.begin();
            it != frequencies.end(); ++it) {
        alphabet.push_back(it->first);
    }

    /**********************************/
    /******* COMPLETE CODE HERE *******/

    double basic_code_bits = ceil(log2(alphabet.size()));

    // Sum all frequencies
    // (equals basic_code_bits if frequencies are fractional)
    double msg_length = 0;
    for (int i=0; i < alphabet.size(); i++) {
        // Add the contribution of each letter to the code by multiplying its
        // frequency of occurrence with the (uniform) codeword length
        msg_length += basic_code_bits * frequencies[alphabet[i]];
    }

    // Number of bits used, on average, with basic uniform encoding
    return msg_length;
}

double code_length(map<string, double> & frequencies,
                   map<string, string> & code) {
    /* Calculate the "message length" using the frequencies of each symbol in
    the alphabet and the code specified in the second argument's map. */

    // Get alphabet from map keys
    vector<string> alphabet;
    for (map<string, double>::iterator it=frequencies.begin();
            it != frequencies.end(); ++it) {
        alphabet.push_back(it->first);
    }

    /**********************************/
    /******* COMPLETE CODE HERE *******/

    // Total message length equal to frequencies multiplied by the number of
    // bits for each codeword
    double msg_length = 0;
    for (int i=0; i < alphabet.size(); i++) {
        // Add the contribution of each letter to the code by multiplying its
        // frequency of occurrence with the length of its codeword
        msg_length += code[alphabet[i]].size() * frequencies[alphabet[i]];
    }
    return msg_length;
}

int main(int argc, char* argv[]) {
    // Read original image
    string img_file = "kayak_mat.dat";
    matrix<double> img_mat_0 = img::read_image_file(img_file);

    // Reduce bits per pixel and convert to string encoding
    int nlevels = 8; // Default
    
    // If argument provided to program, assume it is the number of brightness
    // levels
    if (argc == 2) {
        // cout << argv[1] << " " << atoi(argv[1]) << endl;
        nlevels = atoi(argv[1]);
    }
    matrix<string> img_mat = reduce_img_mat(img_mat_0, nlevels);


    /**********************************/
    /******* COMPLETE CODE HERE *******/

    // Calculate frequencies of pixel values
    vector<string> pixel_values;
    map<string, double> pixel_val_freqs;
    for (int i=0; i < img_mat.nrow(); i++) {
        for (int j=0; j < img_mat.ncol(); j++) {
            string pixel_val = img_mat[i][j];
            if (pixel_val_freqs.find(pixel_val) == pixel_val_freqs.end()) {
                pixel_val_freqs.insert(pair<string, double> (pixel_val, 1));
                pixel_values.push_back(pixel_val);
            } else {
                pixel_val_freqs[pixel_val]++;
            }
        }
    }

    // Create Huffman encoding tree
    map<string, huffman::TreeNode> tree =
        huffman_code_tree(pixel_values, pixel_val_freqs);

    // Use encoding tree to build a codeword dictionary
    map<string, string> code = get_code_map(tree, pixel_values);
    huffman::print_code(pixel_values, code, pixel_val_freqs);
    // huffman::print_tree(tree, code, pixel_val_freqs); // for debugging

    // Assess encoding efficiency
    double basic_length = basic_code_length(pixel_val_freqs);
    double encoded_length = code_length(pixel_val_freqs, code);
    cout << "Code efficiency: " << encoded_length << " vs " << basic_length
         << " (" << encoded_length / basic_length << ")\n" << endl;
}
