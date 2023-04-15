#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/// ParseTree data type that is based on binary search tree functions
typedef struct ParsingTree ParsingTree;

// Builds parse tree of a given expression
ParsingTree* buildTree(char string[]);

/// Traverses a parse tree and calculates the expression
int calculate(ParsingTree* tree);

/// Deletes a parse tree
void deleteTree(ParsingTree* tree);