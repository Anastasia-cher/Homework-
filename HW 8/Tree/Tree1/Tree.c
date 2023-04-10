#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Tree.h"

typedef struct Node {
    int key;
    char* value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Node* getNewNode(int key, char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertRecurion(Node** root, int key, char* value) {
    if (*root == NULL) {
        *root = getNewNode(key, value);
    }
    else if (key <= (*root)->key) {
        (*root)->left = insertRecurion(&(*root)->left, key, value);
    }
    else {
        (*root)->right = insertRecurion(&(*root)->right, key, value);
    }
    return *root;
}

void addValue(Tree* tree, int key, char* value) {
    insertRecurion(&(tree->root), key, value);
}

bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    else if (root->key == key) {
        return true;
    }
    else if (key <= root->key) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

char* getValueRecursion(Node* root, int key) {
    if (root == NULL) {
        return;
    }
    else if (root->key == key) {
        return root->value;
    }
    else if (key <= root->key) {
        return getValueRecursion(root->left, key);
    }
    else {
        return getValueRecursion(root->right, key);
    }
}

char* getValue(Tree* tree, int key) {
    return getValueRecursion(tree->root, key);
}

bool contains(Tree* tree, int key) {
    if (search(tree->root, key)) {
        return true;
    }
    return false;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteRecursion(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    else if (key < root->key) {
        root->left = deleteRecursion(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteRecursion(root->right, key);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root->value);
            free(root);
            root = NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp->value);
            free(temp);
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp->value);
            free(temp);
        }
        else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteRecursion(root->right, key);
        }
        return root;
    }
}

void deleteKey(Tree* tree, int key) {
    deleteRecursion(tree->root, key);
}

Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

void postorderRecursion(Node* root) {
    if (root == NULL) {
        return;
    }
    postorderRecursion(root->left);
    postorderRecursion(root->right);
    free(root->value);
    free(root);
}

void deleteTree(Tree* tree) {
    postorderRecursion(tree->root);
}