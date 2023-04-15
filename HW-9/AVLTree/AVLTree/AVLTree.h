#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tree Tree;

// Function that allocates memory for tree.
Tree* createTree();

// A function that deletes a value for a given key and the key itself.
void deleteKey(Tree* tree, char* key);

// A function that checks for the presence of a key.
bool isKeyHere(Tree* tree, char* key);

// Function that adds new element to the top of the tree.
void insert(Tree* tree, char* key, char* data);

// A function that gets a value by a given key.
char* getValue(Tree* tree, char* key);

// Function that frees memory from tree.
void deleteTree(Tree* tree);

// A function that changes the value by a given key.
void changeData(Tree* tree, char* key, char* newData);
