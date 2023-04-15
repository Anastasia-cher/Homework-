#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ParsingTree.h"

typedef struct Node {
    int operand;
    char operation;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct ParsingTree {
    Node* root;
} ParsingTree;

ParsingTree* createTree() {
    ParsingTree* tree = (ParsingTree*)malloc(sizeof(ParsingTree));
    if (tree == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    tree->root = NULL;
    return tree;
}

bool isOperation(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int number(char* string, int position) {
    int number = 0;
    while (string[position] >= '0' && string[position] <= '9') {
        number = number * 10 + (string[position] - '0');
        position++;
    }
    return number;
}

Node* newNode(char* string, int position) {
    position++;
    while (string[position] == ' ' || string[position] == '(' || string[position] == ')') {
        position++;
    }

    Node* root = (Node*)malloc(sizeof(Node));
    if (isOperation(string[position])) {
        root->operation = string[position];
        root->left = newNode(string, position);
        root->right = newNode(string, position);
    }
    else {
        root->operand = number(string, position);
    }
    return root;
}

ParsingTree* buildTree(char string[]) {
    ParsingTree* tree = createTree();
    int position = -1;
    tree->root = newNode(string, &position);
    return tree;
}

int calculateSubtree(Node* root) {
    if (root->operation == '+') {
        return calculateSubtree(root->left) + calculateSubtree(root->right);
    }
    else if (root->operation == '-') {
        return calculateSubtree(root->left) - calculateSubtree(root->right);
    }
    else if (root->operation == '*') {
        return calculateSubtree(root->left) * calculateSubtree(root->right);
    }
    else if (root->operation == '/') {
        return calculateSubtree(root->left) / calculateSubtree(root->right);
    }
    else {
        return root->operand;
    }
}

int calculate(ParsingTree* tree) {
    return calculateSubtree(tree->root);
}

void deleteRecursion(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteRecursion(root->left);
    deleteRecursion(root->right);
    free(root);
}

void deleteTree(ParsingTree* tree) {
    deleteRecursion(tree->root);
}