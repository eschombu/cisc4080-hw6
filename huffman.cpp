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

    /**********************************/
    /**********************************/

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

    // Build binary tree for encoding, keeping it full as nodes are joined. The
    // nodes should all end up stored in the 'nodes' map created above.

    // The root of the tree should have its parent be itself (i.e., the parent
    // string in the node should equal the nodes label)

    /**********************************/
    /**********************************/


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

    /**********************************/
    /**********************************/

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
    
    //double basic_code_bits = ...

    // Total message length equal to frequencies multiplied by the number of
    // bits for each codeword
    //return msg_length;

    /**********************************/
    /**********************************/
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
    //return msg_length;

    /**********************************/
    /**********************************/
}

int main(int argc, char *argv[]) {
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
    //...

    /**********************************/
    /**********************************/


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
