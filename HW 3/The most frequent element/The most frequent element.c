#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int array[], int left, int right) {
    const int pivot = array[left];
    int low = left;
    int high = right;
    while (low < high) {
        if (array[low] < pivot) {
            low++;
        }
        else if (array[high] >= pivot) {
            high--;
        }
        else {
            const int temp = array[low];
            array[low] = array[high];
            array[high] = temp;
        }
    }
    if (low == left) {
        low = left + 1;
    }
    return low;
}

void qsort(int array[], int left, int right) {
    if (right - left > 0) {
        const int pivot = partition(array, left, right);
        qsort(array, left, pivot - 1);
        qsort(array, pivot, right);
    }
}

int searchOfMinMostFrequent(int array[], int lengthOfArray) {
    qsort(array, 0, lengthOfArray - 1);
    int mostFrequent = array[0];
    int maxCounter = 1;
    int tempCounter = 1;
    for (int i = 1; i < lengthOfArray; i++) {
        if (array[i] == array[i - 1]) {
            tempCounter++;
        }
        else {
            tempCounter = 1;
        }

        if (tempCounter > maxCounter) {
            maxCounter = tempCounter;
            mostFrequent = array[i];
        }
    }
    return mostFrequent;
}

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
    printf("Enter the amount of array elements: ");
    int amountElements = 0;
    scanf_s("%d", &amountElements);
    srand(time(NULL));
    int* array = (int*)malloc(amountElements * sizeof(int));
    printf("\nRandom array: ");
    for (int i = 0; i < amountElements; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    qsort(array, 0, amountElements - 1);
    int mostFrequent = searchOfMinMostFrequent(array, amountElements);
    printf("\nThe most frequent element is %d\n", mostFrequent);
    free(array);
    return 0;
}