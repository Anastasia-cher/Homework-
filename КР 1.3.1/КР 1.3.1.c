#include <stdio.h>


int reverseNumber(int number) {
    int value = 0;
    while (number){
        value = 10 * value + number % 10;
        number /= 10;
    }
    return value;
}

bool checkReversNumber() {
    bool testPassed = true;
    if (reverseNumber(1) != 1) {
        printf("Error\n");
        testPassed = false;
    }

    if (reverseNumber(12345) != 54321) {
        printf("Error\n");
        testPassed = false;
    }

    if (reverseNumber(5454545) != 5454545) {
        printf("Error\n");
        testPassed = false;
    }

    return testPassed;
}
    
bool main() {
    if (!checkReversNumber()) {
        return false;
    }
    int number = 0;
    printf("Enter a number: ");
    scanf_s("%d", &number);
    if (number == reverseNumber(number)) {
        printf("\nThis number is a palindrome\n");
        return true;
    }
    else {
        printf("\nThis number is NOT a palindrome\n");
        return false;
    }
}