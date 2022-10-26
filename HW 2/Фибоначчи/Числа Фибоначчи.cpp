#include <stdio.h>
#include <time.h> 
#include <stdlib.h> 

int fibonacciRecursive(int n, int *errorCode) {
	if (n <= 0) {
		*errorCode = 1;
		return 0;
	}
	*errorCode = 0;
	if (n <= 2) {
		return 1;
	}
	return fibonacciRecursive(n - 1, errorCode) + fibonacciRecursive(n - 2, errorCode);
}
int fibonacciIter(int n, int *errorCode) {
	int first = 1;
	int second = 1;
	if (n <= 0) {
		*errorCode = 1;
		return 0;
	}
	*errorCode = 0;
	if (n <= 2) {
		return 1;
	}
	for (int i = 1; i < n; i++) {
		first = (second += first) - first;
	}
	
	return first;
}
void testDuration(void) {
	clock_t startIter = 0;
	clock_t stopIter = 0;
	clock_t startRecursive = 0;
	clock_t stopRecursive = 0;
	int errorCode = 0;

	printf("Iter VS Recursive:\n");

	for (int i = 0; i <= 40; i++) {
		startIter = clock();
		fibonacciIter(i,&errorCode);
		stopIter = clock();
		startRecursive = clock();
		fibonacciRecursive(i, &errorCode);
		stopRecursive = clock();

		printf("N = %d. %2.3f | %2.3f seconds\n", i,
			(double)(stopIter - startIter) / CLOCKS_PER_SEC,
			(double)(stopRecursive - startRecursive) / CLOCKS_PER_SEC);
	}
}
int main(void) {
	int x = 0;
	printf("Enter the number of the Fibonacci element: ");
	scanf_s("%d", &x);

	testDuration();

	int errorCode = 0;
	int resultRecursive = fibonacciRecursive(x, &errorCode);
	if (errorCode != 0) {
		printf("\n Enter a value greater than zero");
	}
	else {
		printf("\nRecursive: %d element the Fibonacci number is %d\n", x, resultRecursive);
	}
	int resultIter = fibonacciIter(x, &errorCode);
	if (errorCode != 0) {
		printf("");
	}
	printf("\nIterative: %d element the Fibonacci number is %d\n", x, resultIter);
}

	
	



