﻿#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qsort2.h"
#include "Search.h"

bool checkSortedArray(int array[], int lengthOfArray) {
    for (int i = 0; i < lengthOfArray - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

bool testForQsort() {
    const int length = 13;
    int array[length] = {};
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 10;
    }
    qsort(array, 0, length - 1);
    return checkSortedArray(array, length);
    free(array);
}

bool testWithoutMostFrequentElement() {
    int array[5] = { 3, 4, 2, 5, 1 };
    return searchOfMinMostFrequent(array, 5) == 1;
    free(array);
}

bool testWithAllTheIdenticalElements() {
    int array[4] = { 5, 5, 5, 5 };
    return searchOfMinMostFrequent(array, 4) == 5;
    free(array);
}

bool testWithSomeMostFrequentElements() {
    int array[10] = { 3, 7, 2, 7, 2, 4, 7, 3, 3, 4 };
    return searchOfMinMostFrequent(array, 10) == 3;
    free(array);
}

bool tests() {
    bool testsPassed = true;
    if (!testForQsort()) {
        printf("Error in qsort\n");
        testsPassed = false;
    }
    if (!testWithoutMostFrequentElement()) {
        printf("Error in test without most frequent element\n");
        testsPassed = false;
    }
    if (!testWithAllTheIdenticalElements()) {
        printf("Error in test with all the identical elements\n");
        testsPassed = false;
    }
    if (!testWithSomeMostFrequentElements()) {
        printf("Error in test with some most frequent elements");
        testsPassed = false;
    }
    return testsPassed;
}

int main() {
    if (!tests()) {
        return 1;
    }
    FILE* file = fopen("file.txt ", "r");
    if (!file) {
        printf("File not found");
        return 1;
    }
    int* array = (int*)malloc(1000 * sizeof(int));
    int length = 0;
    while (fscanf_s(file, "%d", &array[length]) != EOF) {
        length++;
    }
    fclose(file);
    if (length > 0) {
        printf("Input data:  ");
        for (int i = 0; i < length; i++) {
            printf("%d ", array[i]);
        }
        qsort(array, 0, length - 1);
        printf("\nMinimum most frequent element: %d", searchOfMinMostFrequent(array, length));
    }
    else {
        printf("Not enough input data");
    }
    free(array);
    return 0;
}