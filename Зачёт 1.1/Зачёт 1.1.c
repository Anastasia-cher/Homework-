#include <stdio.h>
#include "String.h"
#include "String1.c"

bool checkCorrect(char* string1, char* string2) {
    char* result = string(string1);
    if (result == NULL) {
        return 1;
    }
    bool answer = strcmp(result, string2);
    free(result);
    return answer;
}

bool tests() {
    bool testsPassed = true;

    if (!checkCorrect("0", "0")) {
        printf("Error\n);
        testsPassed = false;
    }

    if (!checkCorrect("1", "1")) {
        printf("Error\n);
        testsPassed = false;
    }

    if (!checkCorrect("1010", "10")) {
        printf("Error\n);
        testsPassed = false;
    }

    if (!checkCorrect("1111", "15")) {
        printf("Error\n);
        testsPassed = false;
    }
    return testsPassed;
}


int main(void) {
    if (!tests()) {
        return -1;
    }
    char bin[30] = { 0 };
    printf("Enter a binary number: ");
    scanf_s("%s", bin);
    char* result = string(bin);
    if (result == NULL) {
        printf("\nError\n");
        return -1;
    }
    printf("A number in the decimal system is: %s", result);
    free(result);
}