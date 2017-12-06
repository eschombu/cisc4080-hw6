#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <map>
#include "graph.h"
#include "bin_heap.h"

using namespace std;

const double INF = numeric_limits<double>::infinity();
const string EMPTY = ""; // empty string

map<string, double> Dijkstra(Graph g, string start,
                             map<string, string> & prev) {
    /* Use Dijkstra's algorithm to find shortest path distances from the start
    vertex to all other vertices in the graph g. These distances are stored in
    a map, which is returned by this function. Track the shortest paths using
    the input prev map, which stores the previous vertex in the path to each
    vertex. */

    // Initialize maps containing distances and previous node in path from
    // start to each vertex
    map<string, double> dist;
    for (int i=0; i < g.n_vertices(); i++) {
        dist.insert(pair<string, double> (g.vertices[i], INF));
        prev.insert(pair<string, string> (g.vertices[i], EMPTY));
    }

    /**********************************/
    /******* COMPLETE CODE HERE *******/
    // For starting vertex, set dist to 0 and prev to itself
    dist[start] = 0;
    prev[start] = start;

    // Create priority queue using binary heap;
    // Contains vertices, keyed by their dist values
    BinaryHeap<string, double> Q;
    for (int i=0; i < g.n_vertices(); i++) {
        Q.insert(g.vertices[i], dist[g.vertices[i]]);
    }

    while (Q.size() > 0) {
        string v1 = Q.pop_min();

        for (int i=0; i < g.n_edges(v1); i++) {
            string v2 = g.edges[v1][i];
            double dist_next = dist[v1] + g.edge_lengths[v1][v2];

            if (dist_next < dist[v2]) {
                dist[v2] = dist_next;
                prev[v2] = v1;
                Q.update_key(v2, dist_next);
            }
        }
    }

    return dist;
}

map<string, double> Dijkstra(Graph g, string start) {
    /* Version of Dijkstra that just returns distances and does not track paths
    */
    map<string, string> prev;
    return Dijkstra(g, start, prev);
}

vector<string> get_path(map<string, string> & prev, string end) {
    /* Reconstruct the path to end vertex stored in the prev map, and return
    the vertex-to-vertex path in a vector. */

    vector<string> path;
    
    /**********************************/
    /******* COMPLETE CODE HERE *******/

    // Start at end point
    string next = end;
    path.push_back(next);

    // Until at the beginning of the path, insert previous vertex into path
    while (prev[next] != next) {
        path.insert(path.begin(), prev[next]);
        next = prev[next];
    }

    return path;
}

void test_shortest_paths(const Graph & g) {
    // Shortest route from NY to LA? NY to Miami? NY to Seattle?
    string NY = "New_York_NY";
    map<string, string> prev_from_NY; // filled in by Dijkstra()
    map<string, double> dist_from_NY = Dijkstra(g, NY, prev_from_NY);

    vector<string> destinations;
    destinations.push_back("Los_Angeles_CA");
    destinations.push_back("Miami_FL");
    destinations.push_back("Seattle_WA");
    destinations.push_back("San_Francisco_CA");
    destinations.push_back("Boston_MA");

    for (int i=0; i < destinations.size(); i++) {
        vector<string> path = get_path(prev_from_NY, destinations[i]);
        cout << "Route from " << NY << " to " << destinations[i] << ": ";
        for (int j=0; j < path.size(); j++) {
            cout << path[j];
            if (j < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << " (" << dist_from_NY[destinations[i]] << " miles)" << "\n\n";
    }
}

int main() {
    Graph cities = read_adjacency_file("city_connections.txt", true, false);
    test_shortest_paths(cities);
}
