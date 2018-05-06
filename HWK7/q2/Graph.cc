//
// Created by DING on 2018/3/26.
//

#include <climits>
#include <iostream>
#include <queue>
#include "Graph.h"

Graph::Graph(int size) {
    this->size = size;
    V = new Vertex[size]();
    for (int i = 0; i < size; i++) {
        V[i].color = White;
        V[i].parent = -1;
        V[i].distance = INT_MAX;
        V[i].time_in = -1;
        V[i].time_out = -1;
        V[i].edges = NULL;
    }
}

Graph::~Graph() {
    for (int i = 0; i < size; i++) {
        while (V[i].edges) {
            Edge *edge = V[i].edges;
            V[i].edges = edge->next;
            delete edge;
        }
    }
    delete[] V;
}

void Graph::AddEdge(int u, int v, int weight) {
    Edge *edge = new Edge();
    edge->v = v;
    edge->weight = weight;
    edge->next = V[u].edges;
    V[u].edges = edge;
}

void Graph::AddUndirectedEdge(int u, int v, int weight) {
    AddEdge(u, v, weight);
    AddEdge(v, u, weight);
}

void Graph::Print() {
    std::cout << "Printing graph:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Vertex " << i << ":";
        if (V[i].parent >= 0)
            std::cout << " parent=" << V[i].parent;
        if (V[i].distance < INT_MAX)
            std::cout << " distance=" << V[i].distance;
        if (V[i].time_in >= 0)
            std::cout << " time_in=" << V[i].time_in;
        if (V[i].time_out >= 0)
            std::cout << " time_out=" << V[i].time_out;
        std::cout << ", edges={";
        for (Edge *edge = V[i].edges; edge; edge = edge->next)
            std::cout << ' ' << i << "->" << edge->v;
        std::cout << " }\n";
    }
}

void Graph::BFS(int s) {
    // Initialize
    for (int i = 0; i < size; i++) {
        V[i].color = White;
        V[i].distance = INT_MAX;
        V[i].parent = -1;
    }
    // Initialize vertex s
    V[s].color = Gray;
    V[s].distance = 0;
    // Insert s in queue
    std::queue<int> Q;
    Q.push(s);
    // Process queue
    while (Q.size()) {
        // Extract vertex from queue
        int u = Q.front();
        Q.pop();
        // Traverse adjacency list
        for (Edge *edge = V[u].edges; edge; edge = edge->next) {
            int v = edge->v;
            if (V[v].color == White) {
                V[v].color = Gray;
                V[v].parent = u;
                V[v].distance = V[u].distance + 1;
                Q.push(v);
            }
        }
        // Finish processing vertex
        V[u].color = Black;
    }
}

void Graph::PrintShortestPath(int u, int v) {
    if (u == v) {
        std::cout << u;
    } else if (V[v].parent == -1) {
        std::cout << "unreachable";
    } else {
        PrintShortestPath(u, V[v].parent);
        std::cout << " -> " << v;
    }
}

int Graph::DFSVisit(int u, int time) {
    // Color gray
    V[u].time_in = time++;         // Post-increment
    V[u].color = Gray;
    // Traverse adjacency list
    for (Edge *edge = V[u].edges; edge; edge = edge->next) {
        int v = edge->v;
        if (V[v].color == White) {
            V[v].parent = u;
            time = DFSVisit(v, time);
        }
    }
    // Color black
    V[u].color = Black;
    V[u].time_out = time++;         // Post-increment
    return time;
}

void Graph::DFS(int s) {
    // Initialize all verteces
    for (int i = 0; i < size; i++) {
        V[i].color = White;
        V[i].parent = -1;
        V[i].time_in = -1;
        V[i].time_out = -1;
    }
    // Recursive call to source
    DFSVisit(s, 0);
}

void Graph::Relax(int u, Edge *edge) {
    int v = edge->v;
    if (V[u].distance + edge->weight < V[v].distance &&
        V[u].distance != INT_MAX) {
        V[v].parent = u;
        V[v].distance = V[u].distance + edge->weight;
    }
}

bool Graph::BellmanFord(int s) {
    // Initialize
    for (int i = 0; i < size; i++) {
        V[i].distance = INT_MAX;
        V[i].parent = -1;
    }
    V[s].distance = 0;
    // Perform |V| - 1 passes on all edges
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size; j++)
            for (Edge *edge = V[j].edges; edge; edge = edge->next)
                Relax(j, edge);
    // Check for negative cycles
    for (int i = 0; i < size - 1; i++)
        for (Edge *edge = V[i].edges; edge; edge = edge->next)
            if (V[edge->v].distance > V[i].distance + edge->weight &&
                V[i].distance != INT_MAX)
                return false;
    // All good
    return true;
}

void Graph::Dijkstra(int s) {
    // Initialize
    for (int i = 0; i < size; i++) {
        V[i].distance = INT_MAX;
        V[i].parent = -1;
    }
    V[s].distance = 0;
    // Insert all vertexes in a binary search tree, where the key is the
    // current distance of a vertex (field 'distance'), and the data is the
    // vertex index. Each vertex stores its position in the binary search
    // tree using an iterator (field 'it').
    std::multimap<int, int> tree;
    for (int i = 0; i < size; i++)
        V[i].it = tree.insert(std::pair<int, int>(V[i].distance, i));
    // Iterate until tree is empty
    while (tree.size()) {
        // Get minimum element in tree
        std::multimap<int, int>::iterator it = tree.begin();
        int u = it->second;
        // Remove element from the tree and set its associated iterator
        // to a past-the-end iterator.
        tree.erase(it);
        V[u].it = tree.end();
        // Traverse edges
        for (Edge *edge = V[u].edges; edge; edge = edge->next) {
            // Obtain destination vertex
            int v = edge->v;
            // Check if vertex is in the tree
            bool is_in_tree = V[v].it != tree.end();
            // Extract v from tree to update its key (distance)
            if (is_in_tree)
                tree.erase(V[v].it);
            // Relax edge
            Relax(u, edge);
            // Insert v again with its new key (distance)
            if (is_in_tree)
                V[v].it = tree.insert(std::pair<int, int>(V[v].distance, v));
        }
    }
}

void Graph::DeleteVertex(int u) {
    // Delete the outgoing edges
    while (V[u].edges) {
        Edge *temp = V[u].edges;

        // Delete incoming edges
        int inner_index = V[u].edges->v;
        Edge *pseudo_head = new Edge;
        pseudo_head->next = V[inner_index].edges;
        Edge *cur = pseudo_head;
        while (cur) {
            if(cur->next && cur->next->v == u)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        V[inner_index].edges = pseudo_head->next;

        // Delete outgoing edges
        V[u].edges = temp->next;
        delete temp;
    }

    for (int i = u; i < size - 1; i++) {
        V[i] = V[i + 1];
    }

    size -= 1;

    for (int i = 0; i < size; i++) {
        Edge *pseudo_head = new Edge;
        pseudo_head->next = V[i].edges;
        Edge *cur = pseudo_head;
        while (cur) {
            if(cur->next && cur->next->v > u) {
                cur->next->v -= 1;
                cur = cur->next;
            }
            else
                cur = cur->next;
        }
        V[i].edges = pseudo_head->next;
    }
}

Graph Graph::getBFT(int s) {
    Graph *temp = new Graph(size);

    for (int i = 0; i < size; i++) {
        temp->V[i] = V[i];
    }

    // Initialize
    for (int i = 0; i < size; i++) {
        temp->V[i].color = White;
        temp->V[i].distance = INT_MAX;
        temp->V[i].parent = -1;
    }
    // Initialize vertex s
    temp->V[s].color = Gray;
    temp->V[s].distance = 0;
    // Insert s in queue
    std::queue<int> Q;
    Q.push(s);
    // Process queue
    while (Q.size()) {
        // Extract vertex from queue
        int u = Q.front();
        Q.pop();
        // Traverse adjacency list
        for (Edge *edge = temp->V[u].edges; edge; edge = edge->next) {
            int v = edge->v;
            if (temp->V[v].color == White) {
                temp->V[v].color = Gray;
                temp->V[v].parent = u;
                temp->V[v].distance = temp->V[u].distance + 1;
                Q.push(v);
            }
        }
        // Finish processing vertex
        temp->V[u].color = Black;
    }

    for (int i = 0; i < size; i++) {
        temp->V[i].edges = NULL;
    }

    for (int i = 0; i < size; i++) {
        if (temp->V[i].parent >= 0) {
            int u = temp->V[i].parent;
            temp->AddUndirectedEdge(u, i, 1);
        }
    }

    return *temp;
}

