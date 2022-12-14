#include <stdio.h>
#include "String.h"
#include "String1.c"

int main(void) {
    char bin[30] = { 0 };
    printf("Enter a binary number: ");
    scanf_s("%s", bin);
    char* result = string(bin);
    if (result == NULL) {
        printf("\nError\n");
        return -1;
    }
    printf("A number in the decimal system is: %s", result);
    free(result);
}