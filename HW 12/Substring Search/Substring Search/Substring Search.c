#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "search.h"
#include "tests.c"

#define SIZE 1000

int main(int argc, char* argv[]) {
	if (!tests()) {
		printf("Testing error\n");
		return 1;
	}

    FILE* file = fopen("input.txt", "r");
    char* substring = argv[1];
    char string[SIZE];
    fread(string, 1, SIZE, file);
    printf("%d ", search(string, substring));
    fclose(file);
    return 0;
}