#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "tests.h"
#include "PostfixCalculator.h"

#define SIZE 1000

int main() {
    if (!tests()) {
        printf("Testing error\n");
        return 1;
    }
    int errorCode = 0;
    char string[SIZE] = { 0 };
    printf("Enter postfix expression: ");
    scanf_s("%s", string);
    int result = calculate(string, &errorCode);
    (errorCode < 0) ? printf("Error!\n") : printf("Result: %d", result);
    return 0;
}