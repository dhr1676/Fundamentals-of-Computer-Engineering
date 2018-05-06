#include <iostream>
#include "Graph.h"

int main() {
    // Undirected graph shown in this document for the trace of the BFS
    // algorithm.
    Graph g(8);
    g.AddUndirectedEdge(0, 1);
    g.AddUndirectedEdge(0, 4);
    g.AddUndirectedEdge(1, 5); // 5
    g.AddUndirectedEdge(2, 3);
    g.AddUndirectedEdge(2, 5); // 5
    g.AddUndirectedEdge(2, 6);
    g.AddUndirectedEdge(3, 6);
    g.AddUndirectedEdge(3, 7);
    g.AddUndirectedEdge(5, 6); // 5
    g.AddUndirectedEdge(6, 7);

    std::cout << "** Before deletion of vertex 5 **\n";
    g.Print();

    std::cout << "\n** After deletion of vertex 5 **\n";
    g.DeleteVertex(5);
    g.Print();


}