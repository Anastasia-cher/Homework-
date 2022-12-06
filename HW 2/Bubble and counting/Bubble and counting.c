#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <conio.h>

bool checkSortedArray(int array[], int lengthOfArray) {
	for (int i = 0; i < lengthOfArray - 1; i++) {
		if (array[i] > array[i + 1]) {
			return false;
		}
	}
	return true;
}

void printArray(int array[], int lengthOfArray) {
	for (int i = 0; i < lengthOfArray; i++) {
		printf("%d ", array[i]);
	}
}

void sortByBubble(int array[], int lengthOfArray) {
	for (int i = 0; i < lengthOfArray; i++) {
		for (int j = lengthOfArray - 1; j > i; j--) {
			if (array[j] < array[j - 1]) {
				const int temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
	}
}

int searchMaxInArray(int array[], int lengthOfArray) {
	int max = INT_MIN;
	for (int i = 0; i < lengthOfArray; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

int searchMinInArray(int array[], int lengthOfArray) {
	int min = INT_MAX;
	for (int i = 0; i < lengthOfArray; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	return min;
}

void sortByCount(int array[], int lengthOfArray) {
	const int maxElement = searchMaxInArray(array, lengthOfArray);
	const int minElement = searchMinInArray(array, lengthOfArray);
	const int shift = minElement;
	const int numberOfCounters = maxElement - minElement + 1;

	int* arrayOfCounters = (int*)malloc(numberOfCounters * sizeof(int));
	for (int i = 0; i < lengthOfArray; i++) {
		arrayOfCounters[array[i] - shift]++;
	}

	int  index = 0;
	for (int i = 0; i < numberOfCounters; i++) {
		for (int j = 0; j < arrayOfCounters[i]; j++) {
			array[index] = i + shift;
			index++;
		}
	}
	for (int i = 0; i < numberOfCounters; i++) {
		free(arrayOfCounters[i]);
	}
}

bool testOfsearchMaxInArray() {
	int array[5] = { 3, 4, 2, 5, 1 };
	return searchMaxInArray(array,5) == 5;
}

bool testOfsearchMaxInArrayWithAllTheIdenticalElements() {
	int array[4] = { 5, 5, 5, 5 };
	return searchMaxInArray(array,4) == 5;
}

bool testOfsearchMinInArray() {
	int array[5] = { 3, 4, 2, 5, 1 };
	return searchMaxInArray(array, 5) == 1;
}

bool testOfsearchMinInArrayWithAllTheIdenticalElements() {
	int array[4] = { 2, 2, 2, 2 };
	return searchMinInArray(array, 4) == 2;
}

bool testOfsortByBubble() {
	const int length = 15;
	int array[length] = {};
	srand(time(nullptr));
	for (int i = 0; i < length; i++) {
		array[i] = rand() % 10;
	}
	sortByBubble(array, length - 1);
	return checkSortedArray(array, length);
}

bool testOfsortByCount() {
	const int length = 15;
	int array[length] = {};
	srand(time(nullptr));
	for (int i = 0; i < length; i++) {
		array[i] = rand() % 10;
	}
	sortByCount(array, length - 1);
	return checkSortedArray(array, length);
}

bool tests() {
	bool testsPassed = true;

	if (!testOfsearchMaxInArray()) {
		printf("Error in the test of search max in array");
		testsPassed = false;
	}
	if (!testOfsearchMaxInArrayWithAllTheIdenticalElements()) {
		printf("Error in the test of search max in array with all the identical elements");
		testsPassed = false;
	}
	if (!testOfsearchMinInArray()) {
		printf("Error in the test of search min in array");
		testsPassed = false;
	}
	if (!testOfsearchMinInArrayWithAllTheIdenticalElements()) {
		printf("Error in the test of search min in array with all the identical elements");
		testsPassed = false;
	}
	if (!testOfsortByBubble()) {
		printf("Error in the test of sort by bubble");
		testsPassed = false;
	}
	if (!testOfsortByCount()) {
		printf("Error in the test of sort by count");
		testsPassed = false;
	}
	return testsPassed;
}

int main() {
	if (tests()) {
		printf("Enter length of array: ");
		int length = 0;
		scanf_s("%d", &length);
		srand(time(nullptr));
		int* array = (int*)malloc(length * sizeof(int));
		int* arrayForSortByCount = (int*)malloc(length * sizeof(int));
		printf("\nRandom array: ");
		for (int i = 0; i < length; i++) {
			array[i] = rand() % 100;
			arrayForSortByCount[i] = array[i];
			printf("%d ", array[i]);
		}

		printf("\n");
		printf("\nSorted array by Bubble: ");
		sortByBubble(array, length);
		printArray(array, length);
		for (int i = 0; i < length; i++) {
			free(array[i]);
		}

		sortByCount(arrayForSortByCount, length);
		printf("\nSorted array by Count: ");
		printArray(arrayForSortByCount, length);
		printf("\n");
		for (int i = 0; i < length; i++) {
			free(arrayForSortByCount[i]);
		}
	}
	return 0;
}