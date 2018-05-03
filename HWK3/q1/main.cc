#include <iostream>
#include "Deque.h"

int main() {
    std::cout << "The deque intial length is 5\n" << std::endl;
    Deque deque;
    deque.push_front(4);
    deque.push_front(3);
    deque.push_front(2);
    deque.push_front(1);
    deque.push_front(0);

    std::cout << "Input deque: " << std::endl;
    deque.Print();
    std::cout << "The length is: " << deque.getLength() << std::endl;

    std::cout << "The deque is full now, "
            "if we push new elements in the front or back, we get: " << std::endl;
    deque.push_back(5);
    deque.push_front(5);
    deque.Print();

    std::cout << "If we want to add new elements into the deque, "
            "we need to pop some elements before adding new elements " << std::endl;
    deque.pop_front();
    deque.pop_back();
    deque.Print();

    std::cout << "Then we can add new elements into the deque " << std::endl;
    deque.push_front(5);
    deque.push_back(6);
    deque.Print();

    std::cout << "Then we can test get the front element "
            "and the back elements of the deque. " << std::endl;
    std::cout << "The front: " << deque.get_front() << std::endl;
    std::cout << "The back: " << deque.get_back() << std::endl;

    std::cout << "Then we test the clear function: " << std::endl;
    deque.clear();
    deque.Print();
    return 0;
}