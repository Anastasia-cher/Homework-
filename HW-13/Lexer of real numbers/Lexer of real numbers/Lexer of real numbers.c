#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Lexer of real numbers.h"

bool isDigit(char symbol) {
    return (symbol - '0' <= 9 && symbol - '0' >= 0) ? true : false;
}

bool lexicalAnalyzer(char* string) {
    if (!isDigit(string[0])) {
        return false;
    }
    int length = strlen(string);
    int state = 0;
    for (int i = 0; i < length; i++) {
        char symbol = string[i];
        switch (state) {
        case 0:
            if (isDigit(symbol)) {
                state = 1;
            }
            else {
                return false;
            }
            break;
        case 1:
            if (isDigit(symbol)) {
                state = 1;
            }
            else if (symbol == '.') {
                state = 2;
            }
            else if (symbol == 'E') {
                state = 3;
            }
            else {
                return false;
            }
            break;
        case 2:
            if (isDigit(symbol)) {
                state = 3;
            }
            else {
                return false;
            }
            break;
        case 3:
            if (isDigit(symbol)) {
                state = 3;
            }
            else if (symbol == 'E') {
                state = 4;
            }
            else {
                return false;
            }
            break;
        case 4:
            if (symbol == '-' || symbol == '+' || isDigit(symbol)) {
                state = 5;
            }
            else {
                return false;
            }
            break;
        case 5:
            if (!isDigit(symbol)) {
                return false;
            }
            break;
        }
    }
    return isDigit(string[length - 1]);
}