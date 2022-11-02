#include <stdio.h>
#include <stdlib.h>


int swap(int *a, int *b) {
	if (*a == *b) {
		printf("\nPlease try again and enter different values\n");
		return 0;
	}
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
		return 1;

}

int main() {
	int firstVariable, secondVariable;
	printf("Enter first element: ");
	scanf_s("%d", &firstVariable);
	printf("Enter second element: ");
	scanf_s("%d", &secondVariable);
	if (swap(&firstVariable, &secondVariable)) {
		printf("\nfirstVerible = %d\nsecondVerible = %d\n", firstVariable, secondVariable);
	}
	return 0;
}