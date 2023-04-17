#pragma once
#include <stdbool.h>

typedef struct Node {
    char* value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
}Stack;

//create stack
Stack* createStack();

//Function that adds a new element at the top of the stack.
char* push(Stack* stack, char* value);

//Function that removes a new element at the top of the stack.
char* pop(Stack* stack, int* errorCode);

//Function that checks if the stack is empty.
bool isEmpty(Stack* stack);

//Function that removes all the elements from the stack.
void deleteStack(Stack* stack);

//Function that returns the current element at the top of the stack.
char* top(Stack* stack);