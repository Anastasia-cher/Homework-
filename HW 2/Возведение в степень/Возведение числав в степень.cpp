#include <stdio.h>
#include <stdlib.h>


int degree(int number, int *degree) {
    int result = 1;

    if (*degree < 0) {
        return 0;
    }

    for (int i = 0; i < *degree; i++) {
        result *= number;
    }

    return result;
}

int degreeLog(int numberLog, int degreeLog) {
    int result = 1;

    if (degreeLog < 0) {
        return 0;
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

    if (answerLog == 0) {
        printf("");
    }
    else {
        printf("\nNumber %d to the power of %d\n", number, answerLog);
    }
   
}
