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
