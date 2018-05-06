//
// Created by DING on 2018/3/26.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <map>

class Graph {
    struct Edge {
        int v;
        int weight;
        Edge *next;
    };
    enum Color {
        White,
        Gray,
        Black
    };
    struct Vertex {
        // Used in BFS and DFS
        Color color;
        // Used in all algorithms, either to record a sub-graph forming
        // a tree (breadth-first or depth-first tree) or to record
        // shortest paths.
        int parent;
        // Used in BFS
        int distance;
        // Used in DFS
        int time_in;
        int time_out;
        // Used in Dijkstra(). This are references to the positions in a
        // multimap (binary search tree) where a vertex has been stored.
        std::multimap<int, int>::iterator it;
        // Adjacency list
        Edge *edges;
    };
    // Number of vertices
    int size;
    // Array of vertices
    Vertex *V;

    // Auxiliary function for DFS
    int DFSVisit(int u, int time);

    // Auxiliary function for shortest paths
    void Relax(int u, Edge *edge);

public:
    // Constructor
    Graph(int size);

    // Destructor
    ~Graph();

    // Return the number of vertices
    int getSize() { return size; }

    // Add a new edge connecting vertex 'u' with 'v'.
    void AddEdge(int u, int v, int weight = 1);

    // Adds a new undirected (or bidirectional) edge. This consists in
    // adding one edge u->v and another edge v->u. This function is defined
    // inline.
    void AddUndirectedEdge(int u, int v, int weight = 1);

    // Print the graph
    void Print();

    void Print_2();


    // Run breadth-first search, starting at the given source vertex.
    void BFS(int s);

    // Print the sequence of vertices to traverse for one shortest path
    // connecting u and v. This function relies on a previous call to
    // BFS(u) or any version of the shortest-path algorithms.
    void PrintShortestPath(int u, int v);

    void PrintShortestPath_2(int u, int v);


    // Run depth-first search, starting at the given source vertex.
    void DFS(int s);

    // Bellman-Ford algorithm to calculate single-source shortest paths on a
    // weighted, directed graph with possibly negative weights, but no
    // negative-weighted cycles. The function returns false only in the
    // presence of negative cycles.
    bool BellmanFord(int s);

    // Dijkstra algorithm to calculate single-source shortest paths on a
    // weighted, directed graph with non-negative weights.
    void Dijkstra(int s);

    void DeleteVertex(int u);

    Graph getBFT(int s);
};

#endif