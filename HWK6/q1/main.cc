#include <iostream>
#include <cstdlib>
#include "HashTable.h"
#include "Person.h"
#include "String.h"
int main()
{
    // Create hash table
    HashTable table;

    // Create persons
    Person p1("John", "Smith", 20, "jsmith@neu.edu");
    Person p2("Adam", "Taylor", 25, "ataylor@neu.edu");
    Person p3("Tracy", "Terry", 30, "tterry@neu.edu");
    Person p4("Julie", "Tillman", 35, "jtillman@neu.edu");
    Person p5("Michael", "Mace", 40, "mmace@neu.edu");
    Person p6("Florence", "Tarrance", 45, "ftarrance@neu.edu");
    Person p7("Steven", "Cole", 50, "scole@neu.edu");

    // Insert persons
    table.Insert(&p1.last, &p1);
    table.Insert(&p2.last, &p2);
    table.Insert(&p3.last, &p3);
    table.Insert(&p4.last, &p4);
    table.Insert(&p5.last, &p5);
    table.Insert(&p6.last, &p6);
    table.Insert(&p7.last, &p7);

    // Print all elements
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Listing table...\n";
    table.Print();

    // Case i: a valid successor is obtained
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Case i: a valid successor is obtained" << '\n';
    if (table.Succ(&p2.last)) {
        std::cout << "The given node is: " << '\n';
        p2.last.Print();
        std::cout << "The successor of given node is: " << '\n';
        table.Succ(&p2.last)->Print();
    }
    else
        throw "No successor!";


    // Case ii: a non-existing key is passed
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Case ii: a non-existing key is passed" << '\n';
    std::cout << "Fine successor as the key is 'John'...\n";
    Person su1("Steven", "John", 50, "sjohn@neu.edu");
    if (table.Succ(&su1.last)) {
        std::cout << "The given node is: " << '\n';
        p2.last.Print();
        std::cout << "The successor of given node is: " << '\n';
        table.Succ(&su1.last)->Print();
    }
    else
        throw "No successor!";

    // Case iii: a key without successor is passed
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Case iii: a key without successor is passed" << '\n';
    if (table.Succ(&p7.last)) {
        std::cout << "The given node is: " << '\n';
        p2.last.Print();
        std::cout << "The successor of given node is: " << '\n';
        table.Succ(&p7.last)->Print();
    }
    else
        throw "No successor!";

//    // Query 'Mace'
//    std::cout << '\n' << std::string(40, '=') << '\n';
//    std::cout << "Querying 'Mace'...\n";
//    String s1("Mace");
//    Person *p8 = (Person *) table.Search(&s1);
//    p8->Print();
//
//    // Delete 'Taylor'
//    std::cout << '\n' << std::string(40, '=') << '\n';
//    std::cout << "Deleting 'Taylor' and listing...\n";
//    String s2("Taylor");
//    table.Delete(&s2);
//    table.Print();
// End
    return 0;
}