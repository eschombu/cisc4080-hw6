/* This file defines a binary heap implementation of a priority queue. */

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

template <class data_type, class key_type=double>
class BinaryHeap {
    private:
        vector<data_type> values;
        // map<data_type, key_type> keys;
        vector<key_type> keys;

    public:
        int size() { return values.size(); }

        int get_position(data_type value) {
            /* Returns the position in the heap of the input value. Position
            numbers start at 1 and increase from left to right and from root to
            leaf. */

            // Return index greater than number of elements if item not found
            int position = values.size();
            for (int i=0; i < values.size(); i++) {
                if (values[i] == value) {
                    position = i;
                    break;
                }
            }
            return position + 1;
        }

        data_type pop_min() {
            /* Returns the element (value) with the lowest key, and removes it
            from the heap. An error is thrown if this is called when the heap
            is empty. */

            if (values.size() == 0) {
                throw runtime_error("BinaryHeap is empty!");
            }

            /**********************************/
            /******* COMPLETE CODE HERE *******/

            //data_type min_val = ...
            //return min_val;

            /**********************************/
            /**********************************/
        }

        void sift_down(int position) {
            /* Allow the element at the position in the heap specified by the
            argument to sift down until its descendents have higher keys than
            it does. */

            /**********************************/
            /******* COMPLETE CODE HERE *******/


            /**********************************/
            /**********************************/
        }

        void bubble_up(int position) {
            /* Allow the element at the position in the heap specified by the
            argument to bubble up until its ancestors all have higher keys than
            it does. */

            /**********************************/
            /******* COMPLETE CODE HERE *******/


            /**********************************/
            /**********************************/
        }

        void insert(data_type value, key_type key) {
            /* Insert a new element in the heap with the input value and key,
            and allow it to work its way to the appropriate position in the
            heap. */

            /**********************************/
            /******* COMPLETE CODE HERE *******/


            /**********************************/
            /**********************************/
        }

        void update_key(data_type value, key_type key) {
            /* Update the key for the element specified by the input value to
            the new one specified by the second argument, then allow the
            element to work its way to a new appropriate postition. */            

            /**********************************/
            /******* COMPLETE CODE HERE *******/


            /**********************************/
            /**********************************/
        }

        void print() {
            /* Print the contents of the heap to the screen, starting at the
            root node and proceeding down level by level until all leaves are
            printed. Include keys in parentheses next to the element values. */

            int depth = 0; // tracks the depth from the root in the tree
            int start = 0; // tracks the starting element in the current depth
            int n; // tracks the number of nodes in the current depth level
            while (size() > start) {
                n = pow(2, depth);
                for (int i=0; i < n; i++) {
                    if (start + i < size()) {
                        string val = values[start + i];
                        // cout << val << " (" << keys[val]<< ") ";
                        cout << val << " (" << keys[start + i]<< ") ";
                    } else {
                        break;
                    }
                }
                cout << "\n";
                depth++;
                start += n;
            }
            if (size() == 0) {
                cout << "(heap empty)\n";
            }
            cout << endl;
        }
};
