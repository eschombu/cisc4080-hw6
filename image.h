#include <fstream>
#include <sstream>
#include <string>
#include "matrix.h"

using namespace std;

namespace img {

    string int2string(int i) {
        /* From http://www.cplusplus.com/articles/D9j2Nwbp/. */
        string s =
            static_cast<ostringstream*>( &(ostringstream() << i) )->str(); 
        return s;   
    }

    matrix<double> read_image_file(string filename) {
        ifstream f;
        string line;
        double pixel;

        // Get image dimensions
        int nrow = 0;
        int ncol = 0;
        f.open(filename.c_str());
        if (f.is_open()) {
            do {
                getline(f, line);
                if (line.size() > 0) {
                    istringstream line_stream (line);
                    nrow++;
                    int cols = 0;
                    do {
                        line_stream >> pixel;
                        cols++;
                    } while (!line_stream.eof());

                    // Check that # columns consistent
                    if (nrow == 1) {
                        ncol = cols;
                    } else {
                        if (cols != ncol) {
                            throw runtime_error(
                                "Inconsistent number of columns in image file "
                                + filename);
                        }
                    }
                }
            } while (!f.eof());
        }
        f.close();

        // Now read image into matrix
        int dim[2] = {nrow, ncol};
        matrix<double> img_mat(dim);
        f.open(filename.c_str());
        if (f.is_open()) {
            for (int i=0; i < nrow; i++) {
                getline(f, line);
                istringstream line_stream (line);
                for (int j=0; j < ncol; j++) {
                    line_stream >> img_mat[i][j];
                }
            }
        }
        f.close();

        return img_mat;
    }
}
