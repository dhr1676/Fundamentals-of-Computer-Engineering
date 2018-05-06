#include <iostream>
#include "Graph.h"
#include <sys/time.h>
#include <cstdio>

const char v_name[10] = {'s', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b'};

double getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double sec = (double)tv.tv_sec;         // get sec
    double usec = (double)tv.tv_usec;       // get usec
    return sec * 1000000 + usec;            // return time
}

int main() {

    double begin_time, end_time;

    // Undirected graph shown in this document for the trace of the BFS
    // algorithm.
    Graph g(10);
    g.AddUndirectedEdge(0, 1);
    g.AddUndirectedEdge(0, 2);
    g.AddUndirectedEdge(1, 4);
    g.AddUndirectedEdge(2, 3);
    g.AddUndirectedEdge(3, 4);
    g.AddUndirectedEdge(3, 6);
    g.AddUndirectedEdge(5, 6);
    g.AddUndirectedEdge(5, 8);
    g.AddUndirectedEdge(6, 7);
    g.AddUndirectedEdge(7, 9);
    g.AddUndirectedEdge(8, 9);

    begin_time = getTime();
    g.BellmanFord(0);
    end_time = getTime();
    printf("Time is %.5lf us\n", (end_time - begin_time) );

    // Print graph and shortest paths
    std::cout << "** Bellman-Ford **\n";
    g.Print_2();
//
    std::cout << "\n";
    for (int i = 0; i < g.getSize(); i++) {
        std::cout << "Shorted path from s to " << v_name[i] << ": ";
        g.PrintShortestPath_2(0, i);
        std::cout << '\n';
    }
    std::cout << '\n';

    return 0;
}