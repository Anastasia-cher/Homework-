#include <stdbool.h>
#include <stdio.h>
#include "tests.h"
#include "stack.h"
#include "PostfixCalculator.h"

bool test1() {
    bool testsPassed = true;
    int errorCode = 0;
    char testString1[6] = "2 3 *";
    if (calculate(testString1, &errorCode) != 6) {

    }
    return testsPassed;
}

bool test2() {
    bool testsPassed = true;
    int errorCode = 0;
    char testString2[6] = "4 9 -";
    if (calculate(testString2, &errorCode != -4)) {
        return false;
    }

    return testsPassed;
}

bool test3() {
    bool testsPassed = true;
    int errorCode = 0;
    char testString3[6] = "9 9 +";
    if (calculate(testString3, &errorCode) != 18) {
        return false;
    }
    return testsPassed;
}

bool test4() {
    bool testsPassed = true;
    int errorCode = 0;
    char testString4[6] = "9 3 / ";
    if (calculate(testString4, &errorCode) != 3) {
        return false;
    }
    return testsPassed;
}

bool test5() {
    bool testsPassed = true;
    int errorCode = 0;
    char testString5[12] = "9 6 - 1 2 +";
    if (calculate(testString5, &errorCode) != 9) {
        return false;
    }
    return testsPassed;
}


bool tests() {
    if (!test1()) {
        printf("Error in the test1.\n");
        return false;
    }
    if (!test2()) {
        printf("Error in the test2.\n");
        return false;
    }
    if (test3()) {
        printf("Error in the test3.\n");
        return false;
    }
    if (!test4()) {
        printf("Error in the test4.\n");
        return false;
    }
    if (!test5()) {
        printf("Error in the test5.\n");
        return false;
    }
    return true;
}