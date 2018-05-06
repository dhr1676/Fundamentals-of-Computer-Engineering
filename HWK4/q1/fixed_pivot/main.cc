#include <iostream>
#include <cstdlib>
#include "Vector.h"
#include "Integer.h"
#include <cstdio>
#include <sys/time.h>

double getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double sec = (double)tv.tv_sec;         // get sec
    double usec = (double)tv.tv_usec;       // get usec
    return sec * 1000000 + usec;            // return time
}

int main(int argc, char **argv) {
    // Create vector
    Vector vector;

    double begin_time, end_time;
    int n = atoi(argv[1]);

//    int n = 30;
    // Insert elements
    for (int i = 0; i < n; i++)
        vector.Insert(i, new Integer(n - i - 1));

    // Print all elements
//    vector.Print();
//    std::cout << std::string(40, '-') << '\n';

    // Sort and print again
    begin_time = getTime();

    vector.QuickSort();
//    vector.QuickSortRandomPivot();
//    vector.Print();

    end_time = getTime();
    printf("Time is %.5lf ms\n", (end_time - begin_time) / 1000);

    // Free heap elements in vector
    for (int i = 0; i < vector.GetLength(); i++)
        delete vector.Get(i);

    // End
    return 0;
}