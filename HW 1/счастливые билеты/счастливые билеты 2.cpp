﻿#include <stdio.h>

int main(void) {
	int countOfSum[30] = {0};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				countOfSum[i + j + k]++;
			}
		}
	}

	int countOfTickets = 0;
	for (int i = 0; i < 30; i++) {
		countOfSum[i] = countOfSum[i] * countOfSum[i];
		countOfTickets = countOfTickets + countOfSum[i];
	}
	printf("\nNumber of lucky tickets: %d\n", countOfTickets);
	return 0;
}