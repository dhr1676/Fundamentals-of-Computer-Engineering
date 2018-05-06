#include <iostream>
#include "DoublyLinkedList.h"
#include "Integer.h"

using namespace std;

int main() {
    DoublyLinkedList list;

    list.Insert(new Integer(1));
    list.Insert(new Integer(2));
    list.Insert(new Integer(3));
    list.Insert(new Integer(4));
    list.Insert(new Integer(5));

    cout << "Insert 5 numbers from small to large " << endl;
    list.Print();

    cout << "Move to the head and get the head element" << endl;
    list.Head();
    list.GetCurrent()->Print();

    cout << "Move forward two positions and get the current element" << endl;
    list.Next();
    list.Next();
    list.GetCurrent()->Print();

    cout << "Insert an inter set to 1000 write before integer 3" << endl;
    list.Prev();
    list.Insert(new Integer(1000));
    list.Print();

    cout << "Move back one position and remove the current element, then print" << endl;;
    list.Prev();
    list.Remove();
    list.Print();
    
    return 0;
}