#include "Stack1.h"
#include <stdio.h>
#include <malloc.h>

typedef struct Node;

struct Stack;

int push(Stack* stack, Type value);

Type pop(Stack* stack, int* errorCode);

bool isEmpty(Stack* stack);

void deleteStack(Stack* stack);

Type top(Stack* stack);

Stack* createStack();