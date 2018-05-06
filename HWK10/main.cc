#include <iostream>
#include "Graph.h"
int main()
{
// Undirected graph shown in the trace for the Floyd-Warshall algorithm
// on this document.
    Graph g(7);
    g.AddUndirectedEdge(0, 1);
    g.AddUndirectedEdge(0, 2);
    g.AddUndirectedEdge(0, 5);
    g.AddUndirectedEdge(1, 2);
    g.AddUndirectedEdge(1, 6);
    g.AddUndirectedEdge(2, 3);
    g.AddUndirectedEdge(2, 4);
    g.AddUndirectedEdge(3, 4);
    g.AddUndirectedEdge(3, 5);
    g.AddUndirectedEdge(3, 6);
    g.AddUndirectedEdge(4, 5);
    g.AddUndirectedEdge(4, 6);
    g.AddUndirectedEdge(5, 6);

    std::cout << '\n' << std::string(40, '=') << '\n';
    g.Print();

    std::cout << '\n' << std::string(40, '=') << '\n';
    g.PrintMatrix();

    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Suppose the input of the CliqueExists( ) is k = 4\n";
    if (g.CliqueExists(4)) {
        std::cout << "True!" << '\n';
    } else
        std::cout << "False!" << '\n';

    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Suppose the input of the CliqueExists( ) is k = 5\n";
    if (g.CliqueExists(5)) {
        std::cout << "True!" << '\n';
    } else
        std::cout << "False!" << '\n';

    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Print out the Max Clique\n";
    g.getMaxClique();
}