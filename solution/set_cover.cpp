#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
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

    // Find and add vertex connected to the most uncovered vertices
    while (n_uncovered > 0) {
        string greedy_next = "";
        int new_covered = 0;
        for (int i=0; i < g.n_vertices(); i++) {
            int n_edges_to_uncovered = 0;
            for (int j=0; j < g.n_edges(g.vertices[i]); j++) {
                if (vertex_cover[g.edges[g.vertices[i]][j]] == false) {
                    n_edges_to_uncovered++;
                }
            }
            // If candidate vertex is uncovered, also account for its selection
            // covering it
            if (vertex_cover[g.vertices[i]] == false) {
                n_edges_to_uncovered++;
            }

            // Make this the current best candidate if it covers most new
            // vertices
            if (n_edges_to_uncovered > new_covered) {
                greedy_next = g.vertices[i];
                new_covered = n_edges_to_uncovered;
            }
        }
        covering_vertices.push_back(greedy_next);
        covering_vertex_status[greedy_next] = true;
        vertex_cover[greedy_next] = true;
        for (int j=0; j < g.n_edges(greedy_next); j++) {
            vertex_cover[g.edges[greedy_next][j]] = true;
        }
        n_uncovered -= new_covered;
    }

    return covering_vertices;
}

vector<string> random_edge_cover(Graph g) {
    /* Randomly pick a subset of vertices whose edges cover all vertices in the
    graph. Returns a vector of these vertices' labels. */

    /**********************************/
    /******* COMPLETE CODE HERE *******/

    // Set random number generator seed to current time
    srand(time(NULL));

    // Track uncovered vertices with boolean map and integer counter
    map<string, bool> vertex_cover;  // set values to true when vertex covered

    // Store set of vertices used for covering graph in a vector and a map
    // for quickly checking if vertex in this subset (rather than searching
    // through covering_vertices to check if a given vertex is part of the
    // covering subset)
    vector<string> covering_vertices;         // holds covering vertices subset
    vector<string> not_covering_vertices;     // holds vertices not in
                                              // covering_vertices set
    map<string, bool> covering_vertex_status; // set to true when vertex
                                              // included in covering_vertices
    // Initialize the above indicator maps
    for (int i=0; i < g.n_vertices(); i++){
        vertex_cover.insert(pair<string, bool> (g.vertices[i], false));
        covering_vertex_status.insert(
            pair<string, bool> (g.vertices[i], false));
        not_covering_vertices.push_back(g.vertices[i]);
    }
    int n_uncovered = g.n_vertices();

    // Pick random new vertices to add until all covered
    while (n_uncovered > 0) {
        int rand_next_idx = rand() % not_covering_vertices.size();
        string rand_next = not_covering_vertices[rand_next_idx];
        not_covering_vertices.erase(
            not_covering_vertices.begin() + rand_next_idx);
        covering_vertices.push_back(rand_next);
        
        // Cover this newly picked vertex
        if (vertex_cover[rand_next] == false) {
            vertex_cover[rand_next] = true;
            n_uncovered--;
        }
        // Cover its connected vertices
        for (int j=0; j < g.n_edges(rand_next); j++) {
            if (vertex_cover[g.edges[rand_next][j]] == false) {
                vertex_cover[g.edges[rand_next][j]] = true;
                n_uncovered--;
            }
        }
    }

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

    // Iteratively increase the number of vertices in covering set and try
    // possible combinations until a solution is found
    for (int i=0; i < candidates.size(); i++) {
        // Check if this set covers all vertices
        map<string, bool> vertex_cover;
        for (int j=0; j < g.n_vertices(); j++){
            vertex_cover.insert(
                pair<string, bool> (g.vertices[j], false));
        }
        int n_uncovered = g.n_vertices();
        for (int j=0; j < candidates[i].size(); j++) {
            if (!vertex_cover[candidates[i][j]]) {
                vertex_cover[candidates[i][j]] = true;
                n_uncovered--;
            }
            for (int k=0; k < g.edges[candidates[i][j]].size(); k++) {
                if (!vertex_cover[g.edges[candidates[i][j]][k]]) {
                    vertex_cover[g.edges[candidates[i][j]][k]] = true;
                    n_uncovered--;
                }
            }
        }
        if (n_uncovered == 0) {
            return candidates[i];
        }
    }

    // If we haven't already returned a covering set, grow size of candidates
    vector<vector<string> > new_candidates;
    new_candidates.reserve(
        candidates.size() * (candidates.size() - candidates[0].size()));
    for (int i=0; i < candidates.size(); i++) {
        // Add a new vertex to the candidate set of covering vertices
        for (int j=0; j < g.n_vertices(); j++) {
            if (!set_cover::vector_contains<string>(candidates[i],
                                                    g.vertices[j])) {
                vector<string> new_set (candidates[i]);
                new_set.push_back(g.vertices[j]);
                new_candidates.push_back(new_set);
            }
        }
    }

    return optimal_edge_cover(g, new_candidates);
}


int main(int argc, char *argv[]) {
    cout << "Testing " << argv[0] << " ...\n\n";
    string testfile = argv[1];
    bool verbose = true;

    // Allow second arg to program turning off verbose graph loading
    if (argc > 2) {
        verbose = (bool) atoi(argv[2]);
    }
    Graph g = read_adjacency_file(testfile, false, verbose);

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
