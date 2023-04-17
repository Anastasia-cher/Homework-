#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "stack.h"

#define SIZE 1000

Stack* createStack() {
    Stack* stack = calloc(sizeof(Stack), SIZE);
    return stack;
}

char* push(Stack* stack, char* value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Problems with memory allocation");
        return -1;
    }
    temp->value = value;
    temp->next = stack->head;

    stack->head = temp;
    return 0;
}

char* pop(Stack* stack, int* errorCode) {
    if (isEmpty(stack)) {
        if (errorCode != NULL) {
            *errorCode = -1;
        }

        return 0;
    }
    if (errorCode != NULL) {
        *errorCode = 0;
    }

    char* value = stack->head->value;

    Node* next = stack->head->next;
    free(stack->head);
    stack->head = next;

    return value;
}

bool isEmpty(Stack* stack) {
    return stack->head == NULL;
}

void deleteStack(Stack* stack) {
    while (!isEmpty(stack)) {
        int errorCode = 0;
        pop(stack, &errorCode);
    }
    free(stack);
}

char* top(Stack* stack) {
    return stack->head->value;
}