#include <stdio.h>
#include <string.h>
#include "AVLTree.h"
#include "tests.c"

void begin()
{
    printf("Enter:\n 0 - log off\n");
    printf(" 1 - Add value by key\n");
    printf(" 2 - Get value by key\n");
    printf(" 3 - Check key availability\n");
    printf(" 4 - Delete key and value\n");
}

int main() {
    if (!tests()) {
        return;
    }
    Tree* tree = createTree();
    int choice = 0;
    char valueBuffer[256];
    char keyBuffer[256];
    do {
        begin();
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            break;
        case 1:
            printf("Enter a key: ");
            scanf("%s", keyBuffer);
            printf("Enter a value: ");
            scanf("%s", valueBuffer);
            char* value = (char*)malloc(sizeof(char) * 256);
            char* key = (char*)malloc(sizeof(char) * 256);
            strcpy(key, keyBuffer);
            strcpy(value, valueBuffer);
            if (isKeyHere(tree, keyBuffer)) {
                changeData(tree, key, value);
                break;
            }
            insert(tree, key, value);
            break;
        case 2:
            printf("Enter a key: ");
            scanf("%s", key);
            printf("The value is %s\n", getValue(tree, key));
            break;
        case 3:
            printf("Enter a key: ");
            scanf("%s", key);
            if (isKeyHere(tree, key)) {
                printf("There is such a key in the dictionary\n");
            }
            else {
                printf("There is no such a key in the dictionary\n");
            }
            break;
        case 4:
            printf("Enter a key: ");
            scanf("%s", key);
            if (isKeyHere(tree, key)) {
                deleteKey(tree, key);
            }
        default:
            printf("Invalid input\n");
            break;
        }
    } while (choice != 0);

    deleteTree(tree);
}
