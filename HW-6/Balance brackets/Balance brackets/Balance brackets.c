#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Balance brackets.h"
#include "stack.h"

char brackets(char bracket) {
    if (bracket == '(') {
        return ')';
    }
    else if (bracket == ')') {
        return '(';
    }
    else if (bracket == '[') {
        return ']';
    }
    else if (bracket == ']') {
        return '[';
    }
    else if (bracket == '}') {
        return '{';
    }
    else if (bracket == '{') {
        return '}';
    }

    return '\0';
}

bool checkString(char string[], int size) {
    int errorCode = 0;
    Stack* stack = createStack();
    bool stringBalanced = true;
    for (int i = 0; i < size; i++) {
        switch (string[i]) {
        case '(':
        case '{':
        case '[':
            push(stack, string[i]);
            break;
        case ')':
        case '}':
        case ']':
            if (isEmpty(stack)) {
                deleteStack(stack);
                return false;
            }
            else if (pop(stack, &errorCode) != brackets(string[i])) {
                deleteStack(stack);
                return false;
            }
            break;
        }
    }
    deleteStack(stack);
    return stringBalanced;
}