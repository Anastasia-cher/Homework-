#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"
#include "PostfixCalculator.h"

void performOperation(char operation, Node* stack) {
    const int operand2 = pop(stack, 0);
    const int operand1 = pop(stack, 0);
    if (operation == '+') {
        int result = operand1 + operand2;
        push(stack, result);
    }
    else if (operation == '-') {
        int result = operand1 - operand2;
        push(stack, result);
    }
    else if (operation == '*') {
        int result = operand1 * operand2;
        push(stack, result);
    }
    else {
        int result = operand1 / operand2;
        push(stack, result);
    }
}

bool calculate(char postfixExpression[], int* errorCode) {
    Node* stack = NULL;
    int result = 0;
    const int length = strlen(postfixExpression);
    for (int i = 0; i < length; i++) {
        switch (postfixExpression[i]) {
        case ' ':
            break;
        case '/':
        case '*':
        case '+':
        case '-':
            performOperation(postfixExpression[i], &stack);
            break;
        default: {
            push(&stack, postfixExpression[i] - '0');
            break;
        }
        }
        result = top(stack);
    }
    deleteStack(stack);
    return result;
}