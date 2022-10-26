#include <stdio.h>
#include <stdlib.h>
#include < time.h >


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
    int n = 0;
    int d = 0;
    printf("Enter the numder ");
    scanf_s("%d", &n);
    printf("Enter the degree of numder ");
    scanf_s("%d", &d);
    int answer = degree(n, &d);
    if (answer == 0) {
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
   
}
