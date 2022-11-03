#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int array[], int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		for (int j = i; j > left; j--) {
			if (array[j] < array[j - 1]) {
				int const temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}
}

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
	if (right - left + 1 < 10) {
		insertionSort(array, left, right);
	}
	else {
		const int pivot = partition(array, left, right);
		qsort(array, left, pivot - 1);
		qsort(array, pivot, right);
	}
}
bool tests() {

}
int main() {



	return 0;
}