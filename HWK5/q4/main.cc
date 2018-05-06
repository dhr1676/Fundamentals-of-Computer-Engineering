#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sys/time.h>
#include "Tree.h"
#include "Integer.h"

double getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double sec = (double)tv.tv_sec;         // get sec
    double usec = (double)tv.tv_usec;       // get usec
    return sec * 1000000 + usec;            // return time
}

int main(int argc, char **argv) {
    // Create tree
    int size = atoi(argv[1]);
//    int size = 50;
    double begin_time, end_time;

//    Generate non-repeating random numbers
//    I don't want to simply use rand() to generate random numbers
//    Because repeating numbers may occur
//    So I build an array storing random numbers from 0 - size
//    int a[100];
//    for (int i = 0; i < 100; ++i) {
//        a[i] = i;
//    }
//    for (int j = 99; j >= 1; --j) {
//        std::swap(a[j], a[rand() % j]);
//    }

    Integer *int_array[size];

    begin_time = getTime();
    Tree tree;

    for (int i = 0; i < size; i++) {
        int_array[i] = new Integer(i);
        tree.Insert(int_array[i], int_array[i]);
    }
    end_time = getTime();

    // Print all elements
//    std::cout << '\n' << std::string(40, '=') << '\n';
//    std::cout << "Listing tree...\n";
//    tree.Print();
    std::cout << '\n' << std::string(40, '=') << '\n';
    std::cout << "Tree height is " << tree.getHeight() << std::endl;
    std::cout << "Number of elements is " << size << std::endl;
    printf("Time is %.5lf ms\n", (end_time - begin_time) / 1000);

    // End
    return 0;
}