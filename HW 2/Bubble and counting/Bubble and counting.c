#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <climits>

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

	int* arrayOfCounters = new int[numberOfCounters]();
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
	delete[] arrayOfCounters;
}

int main() {
	printf("Enter length of array: ");
	int length = 0;
	scanf_s("%d", &length);
	srand(time(nullptr));
	int* array = new int[length];
	int* arrayForSortByCount = new int[length]();
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
	delete[] array;

	sortByCount(arrayForSortByCount, length);
	printf("\nSorted array by Count: ");
	printArray(arrayForSortByCount, length);
	printf("\n");
	delete[] arrayForSortByCount;
	return 0;
}
