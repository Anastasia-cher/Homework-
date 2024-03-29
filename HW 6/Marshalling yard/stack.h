﻿#pragma once

#include <stdbool.h>

//struct that holds the element at the top and the pointer to the element under it
typedef struct Node {
    char element;
    struct Node* previous;
} Node;

//Function that adds a new element at the top of the stack
char push(Node** head, char element);

//Function that removes a new element at the top of the stack
char pop(Node** head, int* errorCode);

//Function that checks if the stack is empty
bool isEmpty(Node* head);

//Function that returns the current element at the top of the stack
char top(Node* head);

//Function that removes all the elements from the stack
void deleteStack(Node** head);

//displays stack
void displayStack(Node* stack);

//print stack
const char* printStack(Node* stack);