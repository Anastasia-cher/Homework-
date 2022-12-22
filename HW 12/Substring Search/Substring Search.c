#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 2000

bool matched(char string[], char substring[], int left) {
    int substringLength = strlen(substring);
    for (int i = 0; i < substringLength; i++) {
        if (string[left + i] != substring[i]) {
            return false;
        }
    }
    return true;
}

int search(char string[], char substring[]) {
    int module = 100;
    int stringLength = strlen(string);
    int substringLength = strlen(substring);
    int power = pow(7, substringLength);
    power = power % module;
    int* stringHash = (int*)calloc(strlen(string), sizeof(int));
    int count = 0;
    int substringHash = substring[0] % module;
    for (int i = 1; i < substringLength; i++) {
        substringHash = (substringHash * 7 + substring[i]) % module;
    }

    stringHash[0] = string[0] % module;
    for (int i = 1; i < stringLength; i++) {
        stringHash[i] = (stringHash[i - 1] * 7 + string[i]) % module;
    }
    for (int i = substringLength - 1; i < stringLength; i++) {
        if (i > substringLength - 1) {
            int tempHash = (stringHash[i] - stringHash[i - substringLength] * power) % module;
            if (tempHash < 0) {
                tempHash += module;
            }
            if (tempHash == substringHash && matched(string, substring, i - substringLength + 1)) {
                count++;
            }
        }
        else {
            if (stringHash[i] == substringHash && matched(string, substring, i - substringLength + 1)) {
                count++;
            }
        }
    }
    return count;
}

bool tests() {
    bool testsPassed = true;

    char testString1[] = "ababababa";
    char testSubtring1[] = "aba";
    if (search(testString1, testSubtring1) != 4) {
        printf("ERROR!\nTests failed on a string with substring");
        testsPassed = false;
    }

    char testString2[] = "rrrrrr";
    char testSubtring2[] = "aba";
    if (search(testString2, testSubtring2) != 0) {
        printf("ERROR!\nTests failed on a string without substring");
        testsPassed = false;
    }
    return testsPassed;
}

int main(int argc, char* arg[]) {
    if (!tests()) {
        return 1;
    }
    FILE* file = fopen("file.txt", "r");
    char* substring = arg[1];
    char string[SIZE];
    fread(string, 1, SIZE, file);
    printf("%d ", search(string, substring));
    fclose(file);
    return 0;
}