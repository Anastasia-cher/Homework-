#include <stdio.h>
#include <malloc.h>
#include "stack.h"
#include <stdbool.h>

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

    char* topValue = stack->head->value;
    Node* temp = stack->head->next;
    free(stack->head);
    stack->head = temp;
    return topValue;
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