#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

template <class dType=double>
class matrix {
    /* Class for containing and working with rectangular matrices. Does not
    yet perform matrix algebra, just stores them, checks that they have valid
    shape, and provides access and printing methods. Currently used to store
    path distances between vertices in Graphs.
    */
    private:
        vector<vector<dType> > m;  // storage structure

        bool validate() {
            /* Check that storage structure has rectangular dimensions */
            if (m.size() > 0) {
                int nc = m[0].size();
                for (int i=1; i < m.size(); i++) {
                    if (m[i].size() != nc) {
                        throw runtime_error(
                            "matrix has inconsistent number of columns");
                    }
                }
            }
            return true;
        }

    public:
        int nrow() {
            /* Return number of rows */
            validate();
            return m.size();
        }

        int ncol() {
            /* Return number of columns */
            validate();
            return m.size() > 0 ? m[0].size() : 0;  // 0 cols if 0 rows
        }

        vector<dType>& operator[](int i) {
            /* Access row i */
            validate();
            return m[i];
        }

        matrix() { /* Default constructor does nothing */ }

        matrix(int sz) {
            /* Initialize sz x sz square matrix */
            m.resize(sz);
            for (int i=0; i < sz; i++) {
                m[i].resize(sz);
            }
        }

        matrix(int sz[2]) {
            /* Initialize sz[0] x sz[1] matrix */
            m.resize(sz[0]);
            for (int i=0; i < sz[0]; i++) {
                m[i].resize(sz[1]);
            }
        }

        matrix(int sz, dType value) {
            /* Initialize sz x sz square matrix filled with value */
            m.resize(sz);
            for (int i=0; i < sz; i++) {
                m[i].resize(sz, value);
            }
        }

        matrix(int sz[2], dType value) {
            /* Initialize sz[0] x sz[1] matrix filled with value */
            m.resize(sz[0]);
            for (int i=0; i < sz[0]; i++) {
                m[i].resize(sz[1], value);
            }
        }

        matrix<dType> T() {
            /* Return transposed copy of matrix */
            int s[2] = { ncol(), nrow() };
            matrix<dType> t (s);
            for (int i=0; i < nrow(); i++) {
                for (int j=0; j < ncol(); j++) {
                    t[j][i] = m[i][j];
                }
            }
            return t;
        }

        void transpose() {
            /* Transpose the matrix "in place" (this matrix, not a copy) */
            m = T();
        }

        void print(ostream & stream=cout, bool last_newline=true){
            /* Print the matrix to the input ostream (default: cout) */
            for (int i=0; i < nrow(); i++) {
                for (int j=0; j < ncol(); j++) {
                    stream << m[i][j] << " ";
                }
                if (last_newline || (i < nrow()-1)) stream << "\n";
            }
        }

        void print(string path){
            /* Write the matrix to a file at the input path */
            ofstream f;
            f.open(path.c_str());
            if (f.is_open()) this->print(f, false);
            f.close();
        }
};
