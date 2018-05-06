# HWK6

## Question 1 (5 pt.)   
Hash tables provide more efficient searches than binary search trees, but they do not keep track of the relative order between their elements. Thus, obtaining an element’s successor or predecessor in a hash table is an inefficient operation with linear cost.    
Extend the implementation of class HashTable given in the support material for Unit 4 to include a function that returns an element’s successor, with the following prototype:    

Object *Succ(Object *key);    

The function takes a key as an input argument, and returns the key (not the data) of the successor element. The function returns null if argument key does not correspond to an existing key in the hash table, or if it corresponds to the largest element in the table (one without a successor).   

Extend the main program given in main.cc on the support material for Unit 4 to test your function in three situations: i) a valid successor is obtained, ii) a non-existing key is passed, and iii) a key without successor is passed.

## Question 2 (5 pt.)
Implement a C++ class for a hash table with collision management based on open addressing. Your new HashTable class should have the exact same interface as the hash table given in the support material for Unit 4. The main modifications involve the body of functions Search, Insert, Delete, and Print, as well as the internal fields of the table. 

The new class does not need to support growing the hash table. You can omit function Grow, and just issue an error message in function Insert if the new element exceeds the capacity of the table initially allocated.
