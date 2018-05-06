//
// Created by DING on 2018/4/17.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <cassert>
#include <iostream>
#include <vector>

class Graph {
    struct Edge {
        int weight;
        int distance;
        int parent;
    };
    int size;
    Edge *E;
public:
    // Constructor
    Graph(int size);

    // Destructor
    ~Graph();

    // Getter
    int getSize() { return size; }

    // Return edge u -> v
    Edge *getEdge(int u, int v);

    // Add a new edge connecting vertex 'u' with 'v'.
    void AddEdge(int u, int v, int weight = 1);

    // Add a new undirected (or bidirectional) edge. This consists in
    // adding one edge u->v and another edge v->u.
    void AddUndirectedEdge(int u, int v, int weight = 1);

    // All-sources shortest paths
    void FloydWarshall();

    // Print shortest path for u->v. This function assumes that a
    // previous call has been made to FloydWarshall()
    void PrintShortestPath(int u, int v);

    void Print();

    void PrintMatrix();

    bool isClique(std::vector<int> vertexes);

    bool CliqueExists(int k);

    int all_combine(int length, int* result, int count, const int NUM);

    int getMaxClique();
};

#endif