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

            data_type min_val = values[0];  // get min-key value to return

            // Move last element to the top of the heap and let it sift down
            values[0] = values[values.size() - 1];
            values.pop_back();
            keys[0] = keys[keys.size() - 1];
            keys.pop_back();
            sift_down(1);

            return min_val;
        }

        void sift_down(int position) {
            /* Allow the element at the position in the heap specified by the
            argument to sift down until its descendents have higher keys than
            it does. */

            /**********************************/
            /******* COMPLETE CODE HERE *******/

            // Get children positions
            int child1 = 2 * position;
            int child2 = 2 * position + 1;
            int new_position = position;

            // Check if first child's key smaller than this one
            if (child1 <= size()) {
                if (keys[child1 - 1] < keys[position - 1]) {
                    new_position = child1;
                }
            }

            // Check if second child's key smaller than this one and also
            // smaller than first child's
            if (child2 <= size()) {
                if (keys[child2 - 1] < keys[position - 1]) {
                    if (keys[child2 - 1] < keys[child1 - 1]) {
                        new_position = child2;
                    }
                }
            }

            if (new_position == child1) {
                // Swap values with first child and continue sifting down...
                data_type child_val = values[child1 - 1];
                key_type child_key = keys[child1 - 1];
                values[child1 - 1] = values[position - 1];
                values[position - 1] = child_val;
                keys[child1 - 1] = keys[position - 1];
                keys[position - 1] = child_key;
                sift_down(child1);

            } else if (new_position == child2) {
                // Swap values with second child and continue sifting down...
                data_type child_val = values[child2 - 1];
                key_type child_key = keys[child2 - 1];
                values[child2 - 1] = values[position - 1];
                values[position - 1] = child_val;
                keys[child2 - 1] = keys[position - 1];
                keys[position - 1] = child_key;
                sift_down(child2);
            }
        }

        void bubble_up(int position) {
            /* Allow the element at the position in the heap specified by the
            argument to bubble up until its ancestors all have higher keys than
            it does. */

            /**********************************/
            /******* COMPLETE CODE HERE *******/

            // If key less than parent's key, swap their positions and continue
            // bubbling...
            int parent = position / 2;  // rounds down
            if (parent > 0) {
                if (keys[position - 1] < keys[parent - 1]) {
                    data_type parent_val = values[parent - 1];
                    key_type parent_key = keys[parent - 1];
                    values[parent - 1] = values[position - 1];
                    values[position - 1] = parent_val;
                    keys[parent - 1] = keys[position - 1];
                    keys[position - 1] = parent_key;
                    bubble_up(parent);
                }
            }
        }

        void insert(data_type value, key_type key) {
            /* Insert a new element in the heap with the input value and key,
            and allow it to work its way to the appropriate position in the
            heap. */

            /**********************************/
            /******* COMPLETE CODE HERE *******/

            if (get_position(value) <= size()) {
                cerr << "Element already contained in BinaryHeap, "
                        "not inserting..." << endl;
            } else {
                values.push_back(value);
                keys.push_back(key);
                bubble_up(get_position(value));
            }
        }

        void update_key(data_type value, key_type key) {
            /* Update the key for the element specified by the input value to
            the new one specified by the second argument, then allow the
            element to work its way to a new appropriate postition. */

            /**********************************/
            /******* COMPLETE CODE HERE *******/

            int position = get_position(value);
            if (position > size()) {
                cerr << "Element not in BinaryHeap..." << endl;
            } else {
                keys[position - 1] = key;
                sift_down(position);
                position = get_position(value);
                bubble_up(position);
            }
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
