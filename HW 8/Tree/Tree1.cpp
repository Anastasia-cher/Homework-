#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Tree.h"


void begin() {
    printf("0 - Exit\n");
    printf("1 - Add a value with a correlating key\n");
    printf("2 - Get a value via a key\n");
    printf("3 - Check to see if there's a key in the dictionary\n");
    printf("4 - Delete a key and acorrelating value\n");
}

int main() {
    if (!tests()) {
        return 1;
    }
    Tree* tree = createTree();
    int choice = 0;
    char valueBuffer[256];
    int key = 0;
    do {
        begin();
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            break;
        case 1:
            printf("Enter a key: ");
            scanf_s("%d", &key);
            if (contains(tree, key)) {
                deleteViaKey(tree, key);
            }
            printf("Enter a value: ");
            scanf_s("%s", &valueBuffer);
            char* value = (char*)malloc(sizeof(char) * 256);
            strcpy(value, valueBuffer);
            addValue(tree, key, value);
            break;
        case 2:
            printf("Enter a key: ");
            scanf_s("%d", &key);
            printf("The value is %s\n", getValue(tree, key));
            break;
        case 3:
            printf("Enter a key: ");
            scanf_s("%d", &key);
            if (contains(tree, key)) {
                printf("There is such a key in the dictionary\n");
            }
            else {
                printf("There is no such a key in the dictionary\n");
            }
            break;
        case 4:
            printf("Enter a key: ");
            scanf_s("%d", &key);
            if (contains(tree, key)) {
                deleteViaKey(tree, key);
            }
        default:
            printf("Invalid input\n");
            break;
        }
    } while (choice != 0);

    deleteTree(tree);
}

bool tests() {
    Tree* testTree1 = createTree();
    addValue(testTree1, 100, "123");
    addValue(testTree1, 200, "145");
    addValue(testTree1, 300, "600");
    if (!contains(testTree1, 100)) {
        printf("Insert failed\n");
        return false;
    }
    if (contains(testTree1, 1)) {
        printf("Insert failed on finding a nonexistent key in the dictionary\n");
        return false;
    }
    if (getValue(testTree1, 100) != "123") {
        printf("Get value function failed\n");
        return false;
    }
    if (strcmp(getValue(testTree1, 500), "NULL") != 0) {
        printf("Get value function failed on trying to get a value of a nonexistent key\n");
        return false;
    }
    return true;
}