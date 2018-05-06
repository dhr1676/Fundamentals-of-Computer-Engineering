# HWK7

## Question 1 (5 pt.)
Write a member function for class Graph that removes one vertex of the graph. The function should have the following prototype:

void Graph::DeleteVertex(int u);

Notice that this is a rather complex operation that should run the following actions:   
• Delete all outgoing edges for u.    
• Delete all incoming edges for u.    
• Check the target vertex for all edges, and rename it (decrement it by 1) if it has a higher index than the vertex being removed.
• Remove entry u from the vertex array and decrement the number of vertexes.    

Write a main program that creates a graph, prints it, removes an intermediate vertex (i.e., not the first and not the last) with both incoming and outgoing edges, and prints the resulting graph.

a) (4 pt.) Upload your code in a file named q1.zip. This file should contain all the code needed to compile an run the project. The program should compile and run without errors on the CoE Linux machines.

b) (1 pt.) What is the cost of this operation? Justify your answer.

## Question 2 (5 pt.)

Write a member function for class Graph that returns a new dynamically allocated Graph object containing the breadth-first tree of the current graph (this) given a source vertex s. You can assume that all vertexes in the graph are reachable from s. The prototype of the function should be the following:

Graph *Graph::getBFT(int s);

Write a main program that calls this function for the following graph: 

The main program should then print the BFT by invoking function Print() on the returned Graph
object.

a) (4 pt.) Upload your code in a file named q2.zip. This file should contain all the code needed to compile an run the project. The program should compile and run without errors on the CoE Linux machines.
b) (1 pt.) What is the cost of function getBFT()? Justify your answer.
