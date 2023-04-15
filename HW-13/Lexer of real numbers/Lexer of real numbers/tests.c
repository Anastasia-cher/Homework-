#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Lexer of real numbers.h"
#include "tests.h"

bool tests() {
    char* testString1 = "111";
    if (!lexicalAnalyzer(testString1)) {
        printf("Tests failed on passing a number without floating point");
        return false;
    }

    char* testString2 = "111.222";
    if (!lexicalAnalyzer(testString2)) {
        printf("Tests failed on passing a number with floating point");
        return false;
    }

    char* testString3 = "111E1";
    if (!lexicalAnalyzer(testString3)) {
        printf("Tests failed on passing a number with exponent notation");
        return false;
    }

    char* testString4 = "111.2E+21";
    if (!lexicalAnalyzer(testString4)) {
        printf("Tests failed on passing a number  with exponent notation and order");
        return false;
    }

    char* testString5 = "111a";
    if (lexicalAnalyzer(testString5)) {
        printf("Tests failed on passing a number containing letters");
        return false;
    }

    char* testString6 = "111E";
    if (lexicalAnalyzer(testString6)) {
        printf("Tests failed on passing a number ending with E");
        return false;
    }

    char* testString7 = "111.";
    if (lexicalAnalyzer(testString7)) {
        printf("Tests failed on passing a number ending with \'.\'");
        return false;
    }

    char* testString8 = "";
    if (lexicalAnalyzer(testString8)) {
        printf("Tests failed when there's no number");
        return false;
    }
    return true;
}