// This is Brian's solution to THEORY_2014_S1 question 9

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

double arrayAverage (int array[LENGTH], int n) {
    double mean = 0;
    int sum = 0;
    int count = 0;
    // Sums the entire array
    while (count < (LENGTH – 1)) {
            int sum = sum + array[ count ];
            count++;
    }
    mean = sum / count;
    return mean;
}
