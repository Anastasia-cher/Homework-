#include <stdio.h>
#include "ParsingTree.h"
#include "tests.c"

int main() {
	if (!tests()) {
		printf("Testing error\n");
		return 1;
	}

	FILE* file = fopen("input.txt", "r");
	if (!file) {
		printf("File not found");
		return 1;
	}

	char prefix[1000] = {0};
	fgets(prefix, 1000, file);
	fclose(file);

	ParsingTree* tree = buildTree(prefix);
	printf("\nResult: %d", calculate(tree));

	deleteTree(tree);
	return 0;
}