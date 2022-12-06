#include <stdio.h>
#include <time.h> 
#include <stdlib.h> 

int fibonacciRecursive(int n, int *errorCode) {
    if (n <= 0) {
        *errorCode = 1;
        return 0;
    }
    *errorCode = 0;
    if (n <= 2) {
        return 1;
    }
    return fibonacciRecursive(n - 1, errorCode) + fibonacciRecursive(n - 2, errorCode);
}

int fibonacciIter(int n, int *errorCode) {
    int first = 1;
    int second = 1;
    int temp = 0;
    if (n <= 0) {
        *errorCode = 1;
        return 0;
    }
    *errorCode = 0;
    if (n <= 2) {
        return 1;
    }
    for (int i = 1; i < n; i++) {
        temp = second + first;
        first = temp - first;
        second = temp;
        temp = 0;
    }

    return first;
}

bool testOfFibonacciRecursive() {
    int value1 = 0;
    int errorCode = 0;
    return fibonacciRecursive(value1, &errorCode) == 0;

    int value2 = 2;
    return fibonacciRecursive(value2, &errorCode) == 1;

    int value3 = 3;
    return fibonacciRecursive(value3, &errorCode) == 2;
}

bool testOfFibonacciIter() {
    int value1 = 0;
    int errorCode = 0;
    return fibonacciIter(value1, &errorCode) == 0;

    int value2 = 2;
    return fibonacciIter(value2, &errorCode) == 1;

    int value3 = 3;
    return fibonacciIter(value3, &errorCode) == 2;
}

bool tests() {
    bool testsPassed = true;

    if (!testOfFibonacciRecursive()) {
        printf("Error in the Recursive Fibonacci Test");
        testsPassed = false;
    }

    if (!testOfFibonacciIter()) {
        printf("Error in the Iter Fibonacci Test");
        testsPassed = false;
    }
    return testsPassed;
}

void testDuration(void) {
    int errorCode = 0;

    printf("Iter VS Recursive:\n");

    for (int i = 0; i <= 40; i++) {
        clock_t startIter = 0;
        clock_t stopIter = 0;
        clock_t startRecursive = 0;
        clock_t stopRecursive = 0;
        startIter = clock();
        fibonacciIter(i, &errorCode);
        stopIter = clock();
        startRecursive = clock();
        fibonacciRecursive(i, &errorCode);
        stopRecursive = clock();

        printf("N = %d. %2.3f | %2.3f seconds\n", i,
            (double)(stopIter - startIter) / CLOCKS_PER_SEC,
            (double)(stopRecursive - startRecursive) / CLOCKS_PER_SEC);
    }
}

int main(void) {
    if (tests()) {
        int x = 0;
        printf("Enter the number of the Fibonacci element: ");
        scanf_s("%d", &x);

        testDuration();

        int errorCode = 0;
        int resultRecursive = fibonacciRecursive(x, &errorCode);
        if (errorCode != 0) {
            printf("\nEnter a value greater than zero\n");
        }
        else {
            printf("\nRecursive: %d element the Fibonacci number is %d\n", x, resultRecursive);
        }

        int resultIter = fibonacciIter(x, &errorCode);
        if (errorCode != 0) {
            printf("");
        }
        else {
            printf("\nIterative: %d element the Fibonacci number is %d\n", x, resultIter);
        }
    }
}