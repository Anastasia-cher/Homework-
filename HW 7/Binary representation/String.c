#include "String.h"
#include <stdlib.h>
#include <string.h>

char string(char binStr) {
    size_t size = strlen(binStr);
    int number = 0;
    int quotient = 1;
    for (int i = (int)size - 1; i >= 0; i--) {
        if (binStr[i] != '0' && binStr[i] != '1') {
            return NULL;
        }

        number += (binStr[i] == '1') * quotient;
        quotient *= 2;
    }

    char* result = (char*)calloc(11, sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    itoa(number, result, 10);

    return result;
}