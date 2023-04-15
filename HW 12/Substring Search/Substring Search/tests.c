#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "search.h"

bool test1() {
	char string[] = "banana";
	char subtring[] = "ana";
	return search(string, subtring) == 2;
}

bool test2() {
	char string[] = "abcdefghijklmn";
	char subtring[] = "fhg";
	return search(string, subtring) == -1;
}

bool test3() {
	char string[] = "abcdefghijklmnopqrstuvwxyz123456789";
	char subtring[] = "bcdefghijklmnopqrstuvw";
	return search(string, subtring) == 1;
}

bool tests() {
	if (!test1()) {
		printf("Tests failed on a string that contains templates whose suffixes are postfixes of another templates\n");
		return false;
	}

	if (!test2()) {
		printf("Tests failed on a string that contains no templates\n");
		return false;
	}

	if (!test3()) {
		printf("Tests failed on a string that contains templates\n");
		return false;
	}
	return true;
}