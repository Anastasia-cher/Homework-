#include <stdio.h>
#include "ParsingTree.h"

bool test(char* string, int answer) {
	ParsingTree* tree = buildTree(string);
	const bool testPassed = calculate(tree) == answer;
	deleteTree(tree);
	return testPassed;
}

bool tests() {
	char string1[] = "* (+ 52 71) (- 6 31)";
	const int answer1 = -3075;

	char string2[] = "(- (* 25 (- 70 35))(/ (* (+ 15 110) 6) 7))";
	const int answer2 = 768;

	return test(string1, answer1) && test(string2, answer2);
}