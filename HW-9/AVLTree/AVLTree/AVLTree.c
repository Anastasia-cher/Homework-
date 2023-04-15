#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "AVLTree.h"

typedef struct Node {
    char* key;
    char* data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

typedef struct Tree {
    Node* root;
};

Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

bool isEmpty(Tree* tree)
{
    return tree->root == NULL;
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int maximum(int oneValue, int anotherValue) {
    return (oneValue > anotherValue) ? oneValue : anotherValue;
}

Node* newNode(char* key, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return(newNode);
}

Node* rightRotate(Node* root) {
    Node* leftSubtree = root->left;
    Node* leftSubtreeRightSubtree = leftSubtree->right;

    leftSubtree->right = root;
    root->left = leftSubtreeRightSubtree;

    leftSubtree->height = maximum(height(leftSubtree->left), height(leftSubtree->right)) + 1;
    root->height = maximum(height(root->left), height(root->right)) + 1;

    return leftSubtree;
}

Node* leftRotate(Node* root) {
    Node* rightSubtree = root->right;
    Node* rightSubtreeLeftSubtree = rightSubtree->left;

    rightSubtree->left = root;
    root->right = rightSubtreeLeftSubtree;

    rightSubtree->height = maximum(height(rightSubtree->left), height(rightSubtree->right)) + 1;
    root->height = maximum(height(root->left), height(root->right)) + 1;

    return rightSubtree;
}

int getBalance(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

int balanceAdd(Node* node, int balance, char* key) {
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int balanceDelete(Node* root, int balance) {
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node* addData(struct Node* node, char* key, char* data) {
    if (node == NULL) {
        return (newNode(key, data));
    }
    if (strcmp(key, node->key) < 0) {
        node->left = addData(node->left, key, data);
    }
    else if (strcmp(key, node->key) > 0) {
        node->right = addData(node->right, key, data);
    }
    else {
        return node;
    }

    node->height = 1 + maximum(height(node->left),
        height(node->right));

    int balance = getBalance(node);
    balanceAdd(node, balance, key);
}

struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, char* key) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(key, root->key) < 0) {
        root->left = deleteNode(root->left, key);
    }
    else if (strcmp(key, root->key) > 0) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }
            free(temp);
        }
        else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + maximum(height(root->left), height(root->right));
    int balance = getBalance(root);
    balanceDelete(root, balance);
}

void deleteKey(Tree* tree, char* key) {
    tree->root = deleteNode(tree->root, key);
}

Node* findNodeByKey(Node* root, char* key) {
    if (root->key == key) {
        return root;
    }
    else if (strcmp(key, root->key) > 0) {
        return findNodeByKey(root->right, key);
    }
    else {
        return findNodeByKey(root->left, key);
    }
}

bool containsKey(Node* root, char* key) {
    if (root == NULL) {
        return false;
    }

    if (key == root->key)
    {
        return true;
    }

    return key <= root->key ? containsKey(root->left, key) : containsKey(root->right, key);
}

bool isKeyHere(Tree* tree, char* key) {
    return containsKey(tree->root, key);
}

void insert(Tree* tree, char* key, char* data) {
    tree->root = addData(tree->root, key, data);
}

char* get(Node* root, char* key) {
    if (root == NULL) {
        return "NULL";
    }
    else if (root->key == key) {
        return root->data;
    }
    else if (key <= root->key) {
        return get(root->left, key);
    }
    else {
        return get(root->right, key);
    }
}

char* getValue(Tree* tree, char* key) {
    return get(tree->root, key);
}

void deleteRoot(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteRoot(root->left);
    deleteRoot(root->right);
    free(root);
}

void deleteTree(Tree* tree) {
    deleteRoot(tree->root);
}

void changeData(Tree* tree, char* key, char* newData) {
    Node* temp = findNodeByKey(tree->root, key);
    temp->data = newData;
}