#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void output(int** array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swap(int** array, int row1, int row2, int length) {
    for (int i = 0; i < length; i++) {
        int temp = array[i][row1];
        array[i][row1] = array[i][row2];
        array[i][row2] = temp;
    }
}

void sort(int** array, int rows, int columns) {
    for (int i = 0; i < columns; i++) {
        for (int j = i; j < columns; j++) {
            if (array[0][i] > array[0][j]) {
                swap(array, i, j, rows);
            }
        }
    }
}

bool isSorted(int** array, int columns) {
    for (int i = 0; i < columns - 1; i++) {
        if (array[0][i] > array[0][i + 1]) {
            return false;
        }
    }
    return true;
}

bool tests() {
    bool testsPassed = true;

    int rows = 4;
    int columns = 4;
    int** array = (int**)calloc(sizeof(int*), rows);
    for (int i = 0; i < columns; i++) {
        array[i] = (int*)calloc(sizeof(int), columns);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = 0;
        }
    }

    if (!isSorted(array, columns)) {
        printf("Error with the same values");
        testsPassed = false;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = rand() % 100;
        }
    }
    sort(array, rows, columns);
    if (!isSorted(array, columns)) {
        printf("Error with the random values");
        testsPassed = false;
    }
    free(array);
    return testsPassed;
}

int main() {
    if (!tests()) {
        return 1;
    }
    int rows = 5;
    int columns = 5;
    srand(time(NULL));
    int** array = (int**)calloc(sizeof(int*), rows);
    for (int k = 0; k < columns; k++) {
        array[k] = (int*)calloc(sizeof(int), columns);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = rand() % 100;
        }
    }
    printf("Array: \n");
    output(array, rows, columns);
    sort(array, rows, columns);
    printf("Sorted array: \n");
    output(array, rows, columns);
    free (array)
    return 0;
}
