#pragma once
#include <stdbool.h>
#include "typeDef.h"

typedef struct Stack Stack;

//Function that adds a new element at the top of the stack
int push(Stack* stack, Type element);

//Function that removes a new element at the top of the stack
Type pop(Stack* stack, int* errorCode);

//Function that checks if the stack is empty
bool isEmpty(Stack* stack);

//create stack
Stack* createStack(void);

//Function that removes all the elements from the stack
void deleteStack(Stack* stack);

//Function that returns the current element at the top of the stack
Type top(Stack* stack);