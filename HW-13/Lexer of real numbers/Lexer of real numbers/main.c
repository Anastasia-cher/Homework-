#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Lexer of real numbers.h"
#include "tests.h"

int main() {
    if (!tests()) {
        return 1;
    }
    char* string = "2.4E+100";
    (lexicalAnalyzer(string)) ? printf("It's a real number\n") : printf("It's not a real number\n");
    return 0;
}