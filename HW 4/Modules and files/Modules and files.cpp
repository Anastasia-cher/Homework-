#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qsort.h"
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
	srand(time(nullptr));
	for (int i = 0; i < length; i++) {
		array[i] = rand() % 10;
	}
	qsort(array, 0, length - 1);
	return checkSortedArray(array, length);
}

bool testWithoutMostFrequentElement() {
	int array[5] = { 3, 4, 2, 5, 1 };
	return searchOfMinMostFrequent(array, 5) == 1;
}

bool testWithAllTheIdenticalElements() {
	int array[4] = { 5, 5, 5, 5 };
	return searchOfMinMostFrequent(array, 4) == 5;
}

bool testWithSomeMostFrequentElements() {
	int array[10] = { 3, 7, 2, 7, 2, 4, 7, 3, 3, 4 };
	return searchOfMinMostFrequent(array, 10) == 3;
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
