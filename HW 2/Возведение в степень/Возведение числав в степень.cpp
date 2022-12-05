#include <stdio.h>
#include <stdlib.h>


int degree(int number, int degree) {
    int result = 1;

    if (degree < 0) {
        return 0;
    }

    for (int i = 0; i < degree; i++) {
        result *= number;
    }

    return result;
}

int degreeLog(int numberLog, int degreeLog) {
    int result = 1;

    if (degreeLog < 0) {
        return -1;
    }

    while (degreeLog) {
        if (degreeLog % 2 == 0) {
            degreeLog /= 2;
            numberLog *= numberLog;
        }
        else {
            degreeLog--;
            result *= numberLog;
        }
    }
    return result;
}

<<<<<<< HEAD
bool testForDegree() {
    int value1 = 1;
    int testDegree1 = 3;
    return degree(value1, testDegree1) == 1;
=======
int main() {
    int number = 0;
    int degreeOfNumber = 0;
    printf("Enter the numder ");
    scanf_s("%d", &number);
    printf("Enter the degree of numder ");
    scanf_s("%d", &degreeOfNumber);
    int answer = degree(number, &degreeOfNumber);
    if (answer == 0) {
        printf("\nEnter a non-negative degree\n");
    }
    else {
        printf("\nNumber %d to the power of %d\n", number, answer); 
    }
   
    int answerLog = degreeLog(number, degreeOfNumber);
>>>>>>> f5ccc993a6dec6892ea950293ee9d61213630575

    int value2 = -1;
    int testDegree2 = 2;
    return degree(value2, testDegree2) == 1;

    int value3 = -1;
    int testDegree3 = 3;
    return degree(value3, testDegree3) == -1;

    int value4 = 0;
    int testDegree4 = 2;
    return degree(value4, testDegree4) == 0;

    int value5 = 5;
    int testDegree5 = 2;
    return degree(value5, testDegree5) == 25;
}

bool testForDegreeLog() {
    int value1 = 1;
    int testDegree1 = 3;
    return degreeLog(value1, testDegree1) == 1;

    int value2 = -1;
    int testDegree2 = 2;
    return degreeLog(value2, testDegree2) == 1;

    int value3 = -1;
    int testDegree3 = 3;
    return degreeLog(value3, testDegree3) == -1;

    int value4 = 0;
    int testDegree4 = 2;
    return degreeLog(value4, testDegree4) == 0;

    int value5 = 5;
    int testDegree5 = 2;
    return degreeLog(value5, testDegree5) == 25;
}

bool tests() {
    bool testsPassed = true;

    if (!testForDegree()) {
        printf("Error in the exponentiation test");
        testsPassed = false;
    }
<<<<<<< HEAD
    if (!testForDegreeLog()) {
        printf("Error in the logarithm exponentiation test");
        testsPassed = false;
    }
    return testsPassed;
}

int main() {
    if (tests()) {
        int n = 0;
        int d = 0;
        printf("Enter the numder ");
        scanf_s("%d", &n);
        printf("Enter the degree of numder ");
        scanf_s("%d", &d);
        int answer = degree(n, &d);
        if (answer == -1) {
            printf("\nEnter a non-negative degree\n");
        }
        else {
            printf("\nNumber %d to the power of %d\n", n, answer);
        }

        int answerLog = degreeLog(n, d);

        if (answerLog == 0) {
            printf("");
        }
        else {
            printf("\nNumber %d to the power of %d\n", n, answerLog);
        }
=======
    else {
        printf("\nNumber %d to the power of %d\n", number, answerLog);
>>>>>>> f5ccc993a6dec6892ea950293ee9d61213630575
    }
   
}
