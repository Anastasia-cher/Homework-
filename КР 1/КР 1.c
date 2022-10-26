#include <stdio.h>
#include <stdlib.h>

int getSum(int n) {
	int sum = n % 10;
	while (n /= 10) {
		sum += n % 10;
	}
	return sum;
}

int main() {
	int amountOfNumbers = 0;
	printf("Enter amount of number: ");
	scanf_s("%d", &amountOfNumbers);
	printf("\n");
	int array1[] = { 0 };
	int result = 0;
	int maxsum = 0;

	for (int i = 0; i < amountOfNumbers; i++) {
		printf("Enter array elements: array[%d] = ", i);
		scanf_s("%d", &array1[i]);
		for (int k = 0; k < amountOfNumbers; k++) {
			int number = array1[k];
			int sum = getSum(number);
			if (sum > maxsum) {
				maxsum = sum;
			}
		}
	}
	for (int k = 0; k < amountOfNumbers; k++) {
		int number = array1[k];
		int sum = getSum(number);
		if (sum == maxsum) {
			result = number;
			printf("\nThe maximum sum of digits is %d of the number %d\n", maxsum, result);
		}
	}
	return 0;
}
