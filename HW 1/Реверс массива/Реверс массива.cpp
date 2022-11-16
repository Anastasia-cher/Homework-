#include <stdio.h>
#include <stdlib.h>

void revers(int array[], int value, int numberOfElements) {
	for (int i = value; i < numberOfElements / 2; i++) {
		int temp = array[i + 1];
		array[i + 1] = array[numberOfElements - i];
		array[numberOfElements - i] = temp;
	}
}
int main() {
    int numberOfElements1 = 0;
    int numberOfElements2 = 0;
    printf("Enter number of elements 1: ");
	scanf_s("%d", &numberofElements1);
	printf("Enter number of elements 2: ");
	scanf_s("%d", &numberofElements2);
	printf("Enter array: ");
	int array[10000] = {0};
	for (int i = 0; i < numberOfElements1 + numberOfElements2; i++) {
		scanf_s("%d", &array[i + 1]);
	}
	revers(array, 0, m);
	revers(array, m, 2 * m + n);
	revers(array, 0, m + n);
	printf("Inverted array: ");
	for (int i = 0; i < m + n; i++) {
		printf("%d ", array[i + 1]);
	}
    return 0;
}

