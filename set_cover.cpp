#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include "graph.h"
#include "set_cover.h"
// set_cover.h defines an `empty_set` vector and a `vector_contains` function

using namespace std;

vector<string> greedy_edge_cover(Graph g) {
    /* Uses greedy algorithm to pick a subset of vertices whose edges cover all
    vertices in the graph. Returns a vector of these vertices' labels. */

    // Track uncovered vertices with boolean map and integer counter
    map<string, bool> vertex_cover;  // set values to true when vertex covered

    // Store set of vertices used for covering graph in a vector and a map
    // for quickly checking if vertex in this subset (rather than searching
    // through covering_vertices to check if a given vertex is part of the
    // covering subset)
    vector<string> covering_vertices;  // holds covering vertices subset
    map<string, bool> covering_vertex_status;  // set to true when vertex
                                               // included in covering_vertices
    // Initialize the above indicator maps
    for (int i=0; i < g.n_vertices(); i++){
        vertex_cover.insert(pair<string, bool> (g.vertices[i], false));
        covering_vertex_status.insert(
            pair<string, bool> (g.vertices[i], false));
    }
    int n_uncovered = g.n_vertices();

    /**********************************/
    /******* COMPLETE CODE HERE *******/

    /*  Hint: As you are (greedily) selecting the next vertex to include in the
        covering set, be sure to mark that vertex as covered, in addition
        to those it has edges to.  */

    /**********************************/
    /**********************************/

    return covering_vertices;
}

vector<string> random_edge_cover(Graph g) {
    /* Randomly pick a subset of vertices whose edges cover all vertices in the
    graph. Returns a vector of these vertices' labels. */

    /**********************************/
    /******* COMPLETE CODE HERE *******/


    /**********************************/
    /**********************************/

    return covering_vertices;
}

vector<string> optimal_edge_cover(
        Graph g,
        vector<vector<string> > candidates = set_cover::empty_candidates) {
    /* Brute-force search for optimal subset of vertices whose edges cover all
    vertices in the graph. Returns a vector of these vertices' labels. */

    // If no candidates provided, begin with single-element ones
    if (candidates.size() == 0) {
        candidates.reserve(g.n_vertices());
        for (int i=0; i < g.n_vertices(); i++) {
            vector<string> v (1, g.vertices[i]);
            candidates.push_back(v);
        }
    }

    /**********************************/
    /******* COMPLETE CODE HERE *******/

    /*  Hint: If any of candidates covers whole set, return it. otherwise, get
        a new batch of candidates that might cover the whole set and re-run
        the function. */

    // For example:
    //...
    //...
    //vector<vector<string> > new_candidates;
    //...
    //...
    //return optimal_edge_cover(g, new_candidates);

    /**********************************/
    /**********************************/
}


int main(int argc, char *argv[]) {
    cout << "Testing " << argv[0] << " ...\n\n";
    string testfile = argv[1];
    Graph g = read_adjacency_file(testfile, false, true);

    vector<string> greedy_cover = greedy_edge_cover(g);
    cout << "\nCovering vertices from greedy algorithm:";
    for (int i=0; i < greedy_cover.size(); i++) {
        cout << " " << greedy_cover[i];
    }
    cout << " (" << greedy_cover.size() << ")" << endl;

    vector<string> rand_cover = random_edge_cover(g);
    cout << "\nCovering vertices from random algorithm:";
    for (int i=0; i < rand_cover.size(); i++) {
        cout << " " << rand_cover[i];
    }
    cout << " (" << rand_cover.size() << ")" << endl;

    // Only attempt to find optimal solution for a small graph; otherwise you
    // will crash the program as memory and time requirements exponentially
    // increase.
    if (g.n_vertices() < 20) {
        vector<string> optimal_cover = optimal_edge_cover(g);
        cout << "\nCovering vertices from optimal algorithm:";
        for (int i=0; i < optimal_cover.size(); i++) {
            cout << " " << optimal_cover[i];
        }
        cout << " (" << optimal_cover.size() << ")" << endl;
    } else {
        cout << "Graph too large, not attempting optimal search..." << endl;
    }

    cout << endl;
}
