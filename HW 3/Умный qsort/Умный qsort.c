#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LENGTH  10

void output(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

void insertionSort(int array[], int low, int high) {
    for (int i = low; i < high; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= low && array[j] >= key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void swap(int* firstValue, int* secondValue) {
    int temp = *firstValue;
    *firstValue = *secondValue;
    *secondValue = temp;
}

int partition(int array[], int low, int high) {
    int pivotValue = array[high];

    int i = low;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivotValue) {
            swap(&array[j], &array[i]);
            i++;
        }
    }
    swap(&array[high], &array[i]);
    return i;
}

void quickSort(int array[], int low, int high) {
    if (high - low + 1 < 10) {
        insertionSort(array, low, high + 1);
        return;
    }
    if (low < high) {
        int pivotIndex = partition(array, 0, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

bool checkSorted(const int array[], int arrayLength) {
    for (int i = 0; i < arrayLength - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

bool tests() {
    bool testsPassed = true;
    const int arraySize = 100;
    int* testArray = (int*)malloc(arraySize * sizeof(int));
    if (testArray == NULL) {
        printf("Tests failed: No memory\n");
        testsPassed = false;
    }
    for (int i = 0; i < arraySize; i++) {
        testArray[i] = rand() % 100;
    }
    quickSort(testArray, 0, arraySize - 1);
    if (!checkSorted(testArray, arraySize)) {
        printf("Error on an array of 100 elements\n");
        free(testArray);
        testsPassed = false;
    }
    int testArray1[LENGTH] = { 1, 5, 7, 3, 8, 9, 3, 2, 4, 100 };
    quickSort(testArray1, 0, 9);
    if (!checkSorted(testArray1, LENGTH)) {
        printf("Error when pivot is maximum in array\n");
        free(testArray1);
        testsPassed = false;
    }

    int testArray2[LENGTH] = { 155, 8, 3, 7, 9, 2, 3, 4, 132, 1 };
    quickSort(testArray2, 0, 9);
    if (!checkSorted(testArray2, LENGTH)) {
        printf("Error when pivot is minimum in array\n");
        free(testArray2);
        testsPassed = false;
    }

    int testArray3[LENGTH] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    quickSort(testArray3, 0, 9);
    if (!checkSorted(testArray3, LENGTH)) {
        printf("Error when the elements are the same\n");
        free(testArray3);
        testsPassed = false;
    }

    int testArray4[LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    quickSort(testArray4, 0, 9);
    if (!checkSorted(testArray4, LENGTH)) {
        printf("Error when the array is sorted\n");
        free(testArray4);
        testsPassed = false;
    }

    free(testArray);
    return testsPassed;
}

int main() {
    if (!tests()) {
        return 1;
    }
    srand(time(0));
    int size = 0;
    printf("Enter the size of the array:  ");
    scanf_s("%d", &size);
    while (size <= 0) {
        printf("Invalid input! (size must be greater than 0)\n");
        printf("Enter the size of the array:  ");
        scanf_s("%d", &size);
    }

    int* array = malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Out of memory\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Enter the element %d: ", i);
        scanf_s("%d", &array[i]);
    }

    printf("\nThe array: ");
    output(array, size);

    quickSort(array, 0, size - 1);

    printf("\nSorted array: ");
    output(array, size);

    free(array);
    return 0;
}
