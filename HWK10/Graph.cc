//
// Created by DING on 2018/4/17.
//

#include <climits>
#include "Graph.h"

Graph::Graph(int size) {
    this->size = size;
    E = new Edge[size * size]();
    for (int i = 0; i < size * size; i++)
        E[i].weight = INT_MAX;
}

Graph::~Graph() {
    delete E;
}

Graph::Edge *Graph::getEdge(int u, int v) {
    assert(u >= 0 && u < size);
    assert(v >= 0 && v < size);
    return &E[u * size + v];
}

void Graph::AddEdge(int u, int v, int weight) {
    Edge *edge = getEdge(u, v);
    edge->weight = weight;
}

void Graph::AddUndirectedEdge(int u, int v, int weight) {
    AddEdge(u, v, weight);
    AddEdge(v, u, weight);
}

void Graph::FloydWarshall() {
// Initialize
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Edge *edge = getEdge(i, j);
            edge->parent = -1;
            edge->distance = edge->weight;
            if (i == j)
                edge->distance = 0;
            if (edge->weight != INT_MAX)
                edge->parent = i;
        }
    }
// Shortest paths
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                Edge *i_j = getEdge(i, j);
                Edge *i_k = getEdge(i, k);
                Edge *k_j = getEdge(k, j);
                if (i_j->distance > i_k->distance + k_j->distance &&
                    i_k->distance != INT_MAX &&
                    k_j->distance != INT_MAX) {
                    i_j->distance = i_k->distance + k_j->distance;
                    i_j->parent = k_j->parent;
                }
            }
        }
    }
}

void Graph::PrintShortestPath(int u, int v) {
    Edge *edge = getEdge(u, v);
    if (u == v) {
        std::cout << u;
    } else if (edge->parent == -1) {
        std::cout << "unreachable";
    } else {
        PrintShortestPath(u, edge->parent);
        std::cout << " -> " << v;
    }
}

void Graph::Print() {
    std::cout << "Print out the graph" << '\n';
    for (int u = 0; u < size; u++) {
        for (int v = 0; v < size; v++) {
            if (E[u*size+v].weight == 1 and u != v) {
                std::cout << " " << u << " -> " << v << ";";
            }
        }
        std::cout << "\n";
    }
}

void Graph::PrintMatrix() {
    std::cout << "Print out the adjacency matrix" << '\n';
    for (int u = 0; u < size; u++) {
        for (int v = 0; v < size; v ++) {
            if (E[u*size+v].weight <= 1)
                std::cout << E[u*size+v].weight << " ";
            else
                std::cout << "0" << " ";
        }
        std::cout << '\n';
    }
}

bool Graph::isClique(std::vector<int> vertexes) {
    int length = vertexes.size();
    for (int u = 0; u < length; u++) {
        for (int v = 0; v < length; v ++) {
            if (E[vertexes[u]*size+vertexes[v]].weight != 1
                and u != v) {
                return false;
            }
        }
    }
    return true;
}

bool Graph::CliqueExists(int k) {
    int result[k];
    return all_combine(size, result, k, k) > 0;
}

int Graph::all_combine(int length, int* result, int count, const int NUM)
{
    int i;
    int flag = 0;
    for (i = length; i >=count; i--)
    {
        std::vector<int> ans((unsigned)NUM);

        result[count - 1] = i - 1;
//        std::cout << "count is " << count << " r[] is " << result[count - 1] << '\n';
        if (count > 1)
        {
            flag += all_combine(i - 1, result, count - 1, NUM);
        }
        else
        {
//            std::cout << "count is " << count << " ans[] is ";
            int j;
            for (j = NUM - 1; j >=0; j--) {
                ans[j] = result[j];
//                 std::cout << ans[j] << " ";
            }
//            std::cout << '\n';
            if (isClique(ans)) {
//                std::cout << "When k is " << NUM << " the clique vertex is: ";
//                for (int k = 0; k < NUM; k++) {
//                    std::cout << " " << ans[k] << " ";
//                }
//                std::cout << "\n";
                flag += 1;
            }
        }
    }
    return flag ;
}

int Graph::getMaxClique() {
    int result = 0;
    for (int i = 2; i < size+1; i++) {
        if (CliqueExists(i)) {
            if (result < i) {
                result = i;
            }
        }
    }
    std::cout << "The max number of vertexes "
            "forming a clique is " << result << '\n';
    return result;
}