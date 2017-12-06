#include <iostream>
#include <sstream>
#include <string>
#include "bin_heap.h"

using namespace std;

void test_BinHeap() {
    BinaryHeap<string> H;

    // User builds heap by entering values and keys
    cout << "Input items and their keys (separated by whitespace) to insert "
            "into the min-heap. If an item is alread in the heap, the key "
            "will be updated.\n";
    cout << "Hitting 'Enter' with no input stops building the heap and "
            "iteratively pops the minimum key value until it is empty.\n";
    cout << "\n(Item, Key): ";
    string line, item;
    int key;
    
    while (getline(cin, line) && !line.empty()) {
        istringstream line_stream (line);
        line_stream >> item >> key;
        if (H.get_position(item) > H.size()) {
            H.insert(item, key);
        } else {
            H.update_key(item, key);
        }
        cout << "Heap:" << endl;
        H.print();
        cout << "(Item, Key): ";
    }
    cout << endl;

    cout << "Popping items until empty..." << endl;
    while (H.size() > 0) {
        cout << "Pop min: " << H.pop_min() << endl;
        cout << "Heap:" << endl;
        H.print();
    }
    cout << endl;
}

int main() {
    test_BinHeap();
}