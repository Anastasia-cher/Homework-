#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Balance brackets.h"
#include "stack.h"
#include "tests.h"

bool test1() {
    char testString1[5] = "({)}";
    const bool test1Passed = !checkString(testString1, 5);
    return test1Passed;
}

bool test2() {
    char testString2[9] = "({}[()])";
    const bool test2Passed = checkString(testString2, 9);
    return test2Passed;
}


bool tests() {
    if (!(test1())) {
        printf("Error in the test1.\n");
        return false;
    }

    if (!(test2())) {
        printf("Error in the test2.\n");
        return false;
    }

    return true;
}