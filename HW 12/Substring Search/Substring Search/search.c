#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <climits>

bool match(char string[], char substring[], int left) {
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
    int* stringHash = calloc(strlen(string), sizeof(int));
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
            if (tempHash == substringHash && match(string, substring, i - substringLength + 1)) {
                count++;
            }
        }
        else {
            if (stringHash[i] == substringHash && match(string, substring, i - substringLength + 1)) {
                count++;
            }
        }
    }
    return count;
}