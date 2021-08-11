#include <iostream>
#include <vector>

// Implementing Graph using Adjacency List

// Basic operations to perform on the graph data structure
// 1. Add a vertex
// 2. Add an edge
// 3. Display the graph vertices

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(std::vector<int> adj[], int V) {
    for (int v = 0; v < V; ++v) {
        std::cout << "\n Adjencency list of vertex " << v << "\n head ";
        for (auto x : adj[v]) {
            std::cout << "-> " << x;
        }
        std::cout << std::endl;
    }
}

int main() {

    const int V = 7;
    std::vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);

    std::cout << "Printing graph\n";
    printGraph(adj, V);

    return 0;
}