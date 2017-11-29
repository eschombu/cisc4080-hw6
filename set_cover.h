#include <string>
#include <vector>

using namespace std;

namespace set_cover{

    template <class T>
    bool vector_contains(vector<T> v, T id) {
        bool contains = false;
        for (int i=0; i < v.size(); i++) {
            if (v[i] == id) {
                contains = true;
                break;
            }
        }
        return contains;
    }

    vector<vector<string> > empty_candidates;

}
