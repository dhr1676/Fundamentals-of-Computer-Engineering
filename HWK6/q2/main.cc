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

//    Person p4("Julie", "Tillman", 35, "jtillman@neu.edu");
    Person p5("Michael", "Mace", 40, "mmace@neu.edu");
    Person p6("Florence", "Tarrance", 45, "ftarrance@neu.edu");
    Person p7("Steven", "Cole", 50, "scole@neu.edu");

    // Insert persons
    table.Insert_openadd(&p1.last, &p1);
    table.Insert_openadd(&p2.last, &p2);
    table.Insert_openadd(&p3.last, &p3);
    table.Insert_openadd(&p4.last, &p4);
    table.Insert_openadd(&p5.last, &p5);
    table.Insert_openadd(&p6.last, &p6);
    table.Insert_openadd(&p7.last, &p7);
//
    // Print all elements
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Listing table...\n";
    table.Print();


    // Query 'Mace'
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Querying 'Mace'...\n";
    String s1("Mace");
    Person *p8 = (Person *) table.Search_openadd(&s1);
    p8->Print();

    // Delete 'Taylor'
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Deleting 'Taylor' and listing...\n";
    String s2("Taylor");
    table.Delete_openadd(&s2);
    table.Print();

    // End
    return 0;
}