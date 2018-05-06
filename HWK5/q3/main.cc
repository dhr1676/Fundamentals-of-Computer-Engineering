#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Tree.h"
#include "Integer.h"

int main() {
    // Create tree
    Tree tree;
    Integer *p1;
    p1 = new Integer(1);
    Integer *p2;
    p2 = new Integer(2);
    Integer *p3;
    p3 = new Integer(3);
    Integer *p4;
    p4 = new Integer(4);
    Integer *p5;
    p5 = new Integer(5);
    Integer *p6;
    p6 = new Integer(6);

    // Insert persons
//    tree.Insert(p5, p5);
//    tree.Insert(p6, p6);
//    tree.Insert(p2, p2);
//    tree.Insert(p4, p4);
//    tree.Insert(p1, p1);
//    tree.Insert(p3, p3);

    tree.Insert(p3, p3);
    tree.Insert(p4, p4);
    tree.Insert(p5, p5);
    tree.Insert(p6, p6);
    tree.Insert(p2, p2);
    tree.Insert(p1, p1);

//    tree.Insert(p1, p1);
//    tree.Insert(p2, p2);
//    tree.Insert(p3, p3);
//    tree.Insert(p4, p4);
//    tree.Insert(p5, p5);
//    tree.Insert(p6, p6);
    // Print all elements
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Listing tree...\n";
    tree.Print();
    std::cout << "Tree height is " << tree.getHeight() << std::endl;

    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "First right notation :" << std::endl;
    tree.RotateRight();
    tree.Print();

    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Second right notation :" << std::endl;
    tree.RotateRight();
    tree.Print();

    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "First left notation :" << std::endl;
    tree.RotateLeft();
    tree.Print();

    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Second left notation :" << std::endl;
    tree.RotateLeft();
    tree.Print();

    // Query '4'
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Querying '4'...\n";
    Integer s1(4);
    Integer *p8 = (Integer *) tree.Search(&s1);
    p8->Print();

    // Query minimum value
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Querying min...\n";
    Integer *p9 = (Integer *) tree.Min();
    p9->Print();

    // Deleting 'Taylor'
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Deleting '2' and listing...\n";
    Integer s2(2);
    tree.Delete(&s2);
    tree.Print();

    // Query minimum value
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Querying min...\n";
    Integer *p10 = (Integer *) tree.Min();
    p10->Print();
    tree.Print();

    // End
    return 0;
}