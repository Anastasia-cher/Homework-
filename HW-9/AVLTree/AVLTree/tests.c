#include <stdio.h>
#include <string.h>
#include "AVLTree.h"

bool tests() {
    Tree* tree = createTree();
    insert(tree, "1", "123");
    insert(tree, "2", "456");
    insert(tree, "3", "789");
    if (!isKeyHere(tree, "1")) {
        printf("Insert failed\n");
        return false;
    }
    if (isKeyHere(tree, "4")) {
        printf("Insert failed on finding a nonexistent key in the dictionary\n");
        return false;
    }
    if (strcmp(getValue(tree, "1"), "123") != 0) {
        printf("Get value function failed\n");
        return false;
    }
    if (strcmp(getValue(tree, "5"), "NULL") != 0) {
        printf("Get value function failed on trying to get a value of a nonexistent key\n");
        return false;
    }
    return true;
}