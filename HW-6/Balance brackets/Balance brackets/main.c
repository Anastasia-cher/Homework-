#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Balance brackets.h"
#include "stack.h"
#include "tests.h"

int main() {
    if (!tests()) {
        printf("Testing error\n");
        return 1;
    }
    const int size = 0;
    printf("Enter the size of the string: ");
    scanf_s("%d", &size);
    char* string = calloc(sizeof(char), size);
    for (int i = 0; i < size; i++) {
        printf("Enter the bracket %d: ", i);
        scanf_s("%c", &string[i]);
        scanf_s("%*c");
    }
    printf(checkString(string, size) ? "balanced" : "unbalanced");
    free(string);
    return 0;
}