#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Graph {
    /* Stores graph specification through a list of vertices and their
    adjacencies. Vertices and edges are added to the graph through the
    add_vertex(name) and add_edge(v1, v2) methods. Vertices are identified by
    strings, and edges are stored in a map, which uses vertex names as keys to
    vectors of strings containing the ending vertex names for edges starting
    from the vertex labeled by the key.
    */
    public:
        vector<string> vertices;
        map<string, vector<string> > edges;
        map<string, map<string, double> > edge_lengths;

        int n_vertices() {
            /* Return number of vertices */
            return vertices.size();
        }

        int n_edges() {
            /* Return total number of edges */
            int n = 0;
            for (int i=0; i < vertices.size(); i++) {
                n += edges[vertices[i]].size();
            }
            return n;
        }

        int n_edges(string vertex) {
            /* Return number of edges connected to vertex */
            return edges[vertex].size();
        }

        void add_vertex(string name) {
            /* Add a vertex with the specified name to the graph. An error is
            thrown if the graph already has a vertex with that name. */
            vector<string> e;
            map<string, double> w;
            pair<map<string, vector<string> >::iterator, bool> added =
                edges.insert(pair<string, vector<string> >(name, e));
            if (!added.second) {
                cerr << "Graph already has vertex " << name << endl;
                throw runtime_error("duplicate vertex label");
            }
            edge_lengths.insert(pair<string, map<string, double> > (name, w));
            vertices.push_back(name);
        }

        void add_edge(string v1, string v2, double w, bool check_v2=true) {
            /* Add an edge to vertex v2 in the edge list for vertex v1. If
            (optional) check_v2 argument is set to false, does not first check
            to make sure vertex v2 is already in the graph. v2 is NOT added to
            the vertex list if this is set to false. */
            try {
                edges[v1].push_back(v2);
                edge_lengths[v1].insert(pair<string, double> (v2, w));
            } catch (exception& e) {
                cerr << "vertex 1 may not be contained in edge list\n";
                cerr << e.what() << endl;
            }
            if (check_v2) {
                bool v2_found = false;
                int i = 0;
                while (!v2_found && i < vertices.size()) {
                    if (v2 == vertices[i]) v2_found = true;
                    i++;
                }
                if (!v2_found) {
                    cerr << "Downstream vertex in added edge not in vertices"
                         << endl;
                    throw (runtime_error("vertex not found"));
                }
            }
        }

        void add_edge(string v1, string v2, bool check_v2=true) {
            add_edge(v1, v2, 1.0, check_v2);
        }

        bool contains(string vertex) {
            /* Return true if vertex is in graph, otherwise return false */
            return edges.find(vertex) != edges.end();
        }
};

Graph read_adjacency_file(const string & path, bool weighted=false,
                          bool verbose=false) {
    /* Read a text adjacency list file and return the graph it specifies. The
    file should have one line per vertex, starting with the vertex label, which
    may be followed by a colon (':'), but does not have to be. If the optional
    second argument is set to true, the file lines and resulting vertices and
    adjacency list will be printed to cout.
    */
    ifstream f;
    string line;
    Graph graph;

    f.open(path.c_str());
    if (f.is_open()) {
        do {
            getline(f, line);
            if (line.size() > 0) {
                istringstream line_stream (line);
                string v1;

                // First entry is starting vertex, perhaps with colon
                line_stream >> v1;
                int colon_idx = v1.find(':');
                if (colon_idx < v1.npos) {
                    v1 = v1.substr(0, colon_idx);
                }
                graph.add_vertex(v1);

                // List of connected vertices follow
                string v2;
                double w;
                do {
                    line_stream >> v2;

                    // Read edge weight if graph is weighted
                    if (weighted) {
                        line_stream >> w;
                        if (v2.size() > 0) {
                            graph.add_edge(v1, v2, false);
                        }
                    } else {
                        graph.add_edge(v1, v2, false);
                    }
                } while (!line_stream.eof());
            }
        } while (!f.eof());
        if (verbose) cout << endl;
        f.close();
    } else {
        cerr << path << " not found!" << endl;
        return graph;
    }

    if (verbose) {
        cout << "Nodes:\n";
        for (int i = 0; i < graph.n_vertices(); i++) {
            cout << graph.vertices[i];
            if (i < graph.n_vertices() - 1) { cout << ", "; }
        }
        cout << "\n\nEdges:\n";
        for (int i = 0; i < graph.n_vertices(); i++) {
            string orig = graph.vertices[i];
            cout << orig << ": ";
            for (int j = 0; j < graph.n_edges(orig); j++) {
                string dest = graph.edges[orig][j];
                cout << dest;
                if (weighted) {
                    cout << " (" << graph.edge_lengths[orig][dest] << ")";
                }
                if (j < graph.n_edges(orig) - 1) { cout << ", "; }
            }
            cout << "\n";
        }
    }

    return graph;
}
