#include <iostream>
#include "Graph.h"
#include <cstdlib>

int main(int argc, char **argv) {
    float alpha = float(atof(argv[1]));
//    float alpha = 0.8;
    Graph g(8, alpha);

    std::cout <<"\nOriginal Graph is: " << '\n';
    g.Print();

    return 0;
}