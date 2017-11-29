#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace huffman {

    class TreeNode {
        /* For use in forming Huffman prefix-free encoding tree. */

        public:
            string label;
            string parent;
            double freq;
            bool leaf;  // set to false once node has children
            string left;  // left child
            string right;  // right child

            // Empty constructor
            TreeNode() {}

            // Initialize label and frequency at instantiation
            TreeNode(string name, double f) {
                label = name;
                freq = f;
                leaf = true;
            }
    };

    string find_root(map<string, TreeNode> & tree, string start) {
        /* From input start node in tree, recursively jump up parent
        connections until the root node is reached. */

        if (tree[start].parent == tree[start].label) {
            return tree[start].label;
        } else {
            start = tree[tree[start].parent].label;
            return find_root(tree, start);
        }
    }

    string find_root(map<string, TreeNode> & tree) {
        /* From whichever node happens to be at the begin() position in the
        tree map, recursively jump up parent connections until the root node is
        reached. */

        map<string, TreeNode>::iterator it = tree.begin();
        it++;
        string start = tree[it->first].label;
        return find_root(tree, start);
    }

    void print_code(vector<string> & alphabet, map<string, string> & code) {
        /* Print out the codewords for each letter of the encoded alphabet. */

        cout << "   CODE   \n----------\n";
        for (map<string, string>::iterator it=code.begin(); it != code.end(); it++)
        {
            cout << it->first << ": " << it->second << endl;
        }
        cout << endl;
    }

    void print_code(vector<string> & alphabet, map<string, string> & code,
                    map<string, double> & frequencies) {
        /* Print out the codewords for each letter of the encoded alphabet, as
        well as the frequencies of occurrence. */

        cout << "   CODE   \n----------\n";
        for (map<string, string>::iterator it=code.begin(); it != code.end(); it++)
        {
            cout << it->first << " (f=" << frequencies[it->first]
                << "): " << it->second << endl;
        }
        cout << endl;
    }

    void print_tree(map<string, TreeNode> & tree,
                    map<string, string> & code,
                    map<string, double> & frequencies) {
        /* Print out the binary tree used to generate the prefix-free encoding
        of the alphabet, in addition to the frequencies of the letters, which
        lie at the leaves of the tree. */

        cout << "   TREE   \n----------\n";
        vector<string> level_nodes;
        vector<string> next_level;
        level_nodes.push_back(find_root(tree));
        while (level_nodes.size() > 0) {
            next_level.clear();
            for (int i=0; i < level_nodes.size(); i++) {
                string node = level_nodes[i];
                cout << node;
                if (tree[node].leaf) {
                    cout << "=" << code[node];
                }
                cout << " (" << frequencies[node] << "), ";
                if (!tree[node].leaf) {
                    next_level.push_back(tree[node].left);
                    next_level.push_back(tree[node].right);
                }
            }
            cout << endl;
            level_nodes = next_level;
        }
        cout << endl;
    }
}
