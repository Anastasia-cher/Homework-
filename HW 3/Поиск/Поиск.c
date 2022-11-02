#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

bool checkSortedArray(int array[], int lengthOfArray)
{
	for (int i = 0; i < lengthOfArray - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool tests()
{
	bool testsPassed = true;
	const int length = 10;
	int testArray1[length] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	qsort(testArray1, 0, length - 1);
	if (!checkSortedArray(testArray1, length))
	{
		printf("Error in test with array already sorted\n");
		testsPassed = false;
	}

	int testArray2[length] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	qsort(testArray2, 0, length - 1);
	if (!checkSortedArray(testArray2, length))
	{
		printf("Error in test with all the identical elements\n");
		testsPassed = false;
	}

	int testArray3[length] = { 1, 4, 10, 6, 4, 7, 11, 1, 4, 5 };
	qsort(testArray3, 0, length - 1);
	if (!checkSortedArray(testArray3, length))
	{
		printf("Error when pivot is minimum in array\n");
		testsPassed = false;
	}

	int testArray4[length] = { 15, 4, 10, 6, 7, 15, 11, 3, 4, 5 };
	qsort(testArray4, 0, length - 1);
	if (!checkSortedArray(testArray4, length))
	{
		printf("Error when pivot is maximum in array");
		testsPassed = false;
	}
	return testsPassed;
}
