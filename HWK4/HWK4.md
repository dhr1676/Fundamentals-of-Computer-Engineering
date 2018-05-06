# HWK4

## Question 1 (3 pt.)  
Writing a C++ multi-file project with the following characteristics:  
• Use the implementations for Vector.cc and Vector.h available on the support material for Unit 2. Include any additional files needed for the project to compile correctly, such as Object.h.  
• Extend class Vector with functions Vector::QuickSort(), plus an auxiliary function named Vector::QuickSortPartition(). The code for these function is available on the support material for Unit 3. 
• Extend class Vector with functions Vector::QuickSortRandomPivot(), plus an auxiliary function named Vector::QuickSortPartitionRandomPivot(). These functions should implement a version of quicksort that uses a pivot at a random position, by swapping it with the rightmost element in the partition stage.  
• Write a main program in a file named main.cc. This program should take a vector size as an argument, and should initialize the vector with sorted values that will lead to the worst case performance for quicksort. The main program should then run quicksort on the vector, and exit silently. The program should not print the content of the vector. 
• Write a second main program in a separate file named main-random-pivot.cc. The content of this file should be identical to main.cc, except it should run the version of quicksort that uses a random pivot. 

## Question 3 (5 pt.)
A doubly linked list is a linked list where each node has a pointer both to its next node (field next) and its previous node (field prev). The advantage of this type of container versus a singly linked list (one in which there is only a next pointer in each node, as studied in class) is that the list can be traversed both forward and backward. As a downside, each list node increases its memory footprint by requiring the additional prev pointer.  

A small positive side effect of the doubly linked representation is that we can remove field prev within the list structure itself, since the first is accessible in each node individually. The list structure needs to keep track of the current node (field current) and the list head (field head). We will add an additional pointer to the last element in the list in an additional field called tail, set to nullptr if the list is empty. Notice that the tail position is considered to be the position right before past-the-end.  

Create a project composed of filed Object.h, Integer.h/.cc DoublyLinkedList.h/.cc, and main.cc. Follow these steps: 

a) (1 pt.) Create a class called DoublyLinkedList, declared in DoublyLinkedList.h and defined in DoublyLinkedList.cc. The class can use an auxiliary Node data structure representing a node in the list. Implement functions Head(), Tail(), Prev(), and Next(), which move the current element to the head, the tail, the previous, and the next element, respectively. 

b) (1 pt.) Implement function Print(), which traverses the entire list and prints all of its elements by invoking function Object::Print() on each of them. 

c) (1 pt.) Implement function Insert(Object *x), which inserts an object right at the current position in the list. If the current position is past-the-end, the element should be inserted at the end. Remember to update the head and tail pointer appropriately, as well as the next and prev fields of each affected node.  

d) (1 pt.) Implement function Remove(), which removes the object at the current position in the list, other than past-the-end. Remember to update the head and tail pointer appropriately, as well as the next and prev fields of each affected node. 

e) (1 pt.) Write a main program that inserts five integers (wrapped in objects of type Integer) set to 1, 2, 3, 4, and 5, which should appear in the list in that exact order. Move to the head. Move forward two positions. Insert an integer set to 1000 write before integer “3”. Move back one position. Remove the current element. Print the entire list. 
