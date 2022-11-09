#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <climits>

void printArray(int array[], int lengthOfArray) {
	for (int i = 0; i < lengthOfArray; i++) {
		printf("%d ", array[i]);
	}
}

void bubbleSort(int array[], int lengthOfArray) {
	for (int i = 0; i < lengthOfArray; i++) {
		for (int j = lengthOfArray - 1; j > i; j--) {
				if (array[j] < array[j - 1]) {
					if (array[j] % 2 == 0 || array[j - 1] % 2 == 0){
					const int temp = array[j - 1];
					array[j - 1] = array[j];
					array[j] = temp;
				}
			}
		}
	}
}

int main() {
	printf("Enter length of array: ");
	int length = 0;
	scanf_s("%d", &length);
	srand(time(nullptr));
	int* array = new int[length];
	int* arrayForSort = new int[length]();
	printf("\nRandom array: ");
	for (int i = 0; i < length; i++) {
		array[i] = rand() % 100;
		arrayForSort[i] = array[i];
		printf("%d ", array[i]);
	}

	printf("\n");
	printf("\nSorted array by Bubble: ");
	bubbleSort(array, length);
	printArray(array, length);
	printf("\n");
	delete[] array;
	return 0;
}