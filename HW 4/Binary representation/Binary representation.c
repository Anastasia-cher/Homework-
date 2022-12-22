#include <stdio.h>
#include <stdbool.h>

#define SIZE (sizeof(int) * 8)

void convertingDecimalToBinary(int number, int binaryNumber[]) {
    int bit = 1;
    for (int i = SIZE - 1; i >= 0; i--) {
        binaryNumber[i] = ((number & bit) ? 1 : 0);
        number >>= 1;
    }
}

void binOutput(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
}

void binaryAddition(const int number1[], const int number2[], int result[]) {
    int inMind = 0;

    for (int i = SIZE - 1; i >= 0; i--) {
        int interResult = number1[i] + number2[i] + inMind;
        switch (interResult) {
        case 0:
            result[i] = 0;
            inMind = 0;
            break;
        case 1:
            result[i] = 1;
            inMind = 0;
            break;
        case 2:
            result[i] = 0;
            inMind = 1;
            break;
        case 3:
            result[i] = 1;
            inMind = 1;
            break;
        default:
            printf("ERROR!\n");
        }
    }
}

int countZeros(const int binNumber[]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (binNumber[i] == 0) {
            count++;
        }
    }
    return count;
}

int countOnes(const int binNumber[]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (binNumber[i] == 1) {
            count++;
        }
    }
    return count;
}

int convertingBinaryToDecimal(const int binNumber[]) {
    int currentExponent = 1;
    int result = 0;
    for (int i = SIZE - 1; i >= 0; i--) {
        result += binNumber[i] * currentExponent;

        currentExponent *= 2;
    }
    return result;
}

bool convertingDecimalToBinTests() {
    int testValue1 = 100;
    int binValue1[SIZE] = { 0 };
    convertingDecimalToBinary(testValue1, binValue1);
    if (convertingBinaryToDecimal(binValue1) != testValue1) {
        printf("ERROR!\nDecimal to binary convert failed on a positive number");
        return false;
    }

    int testValue2 = -124;
    int binValue2[SIZE] = { 0 };
    convertingDecimalToBinary(testValue2, binValue2);
    if (convertingBinaryToDecimal(binValue2) != testValue2) {
        printf("ERROR!\nDecimal to binary convert failed on a positive number");
        return false;
    }
    return true;
}

bool binaryConvertTests() {
    int testNumber1 = 2049;
    int testBinNumber1[SIZE] = { 0 };
    convertingDecimalToBinary(testNumber1, testBinNumber1);
    if (!(testBinNumber1[SIZE - 1] == 1 && testBinNumber1[SIZE - 12] == 1 && countZeros(testBinNumber1) == 30)) {
        printf("ERROR!\nBinary convert failed on a positive number!\n");
        return false;
    }

    int testNum2 = -257;
    int testBinNum2[SIZE] = { 0 };
    convertingDecimalToBinary(testNum2, testBinNum2);
    if (!(testBinNum2[SIZE - 9] == 0 && countOnes(testBinNum2) == 31)) {
        printf("ERROR!\nBinary convert failed on a negative number!\n");
        return false;
    }
    return true;
}

bool binAdditionTests() {
    int testNumber11 = 1020;
    int testNumber12 = 4;
    int testNumberBin11[SIZE] = { 0 };
    int testNumberBin12[SIZE] = { 0 };
    int result1[SIZE] = { 0 };
    convertingDecimalToBinary(testNumber11, testNumberBin11);
    convertingDecimalToBinary(testNumber12, testNumberBin12);
    binaryAddition(testNumberBin11, testNumberBin12, result1);
    if (!(result1[SIZE - 11] == 1 && countZeros(result1) == 31)) {
        printf("ERROR!\nAddition failed on adding two positive values\n");
        return false;
    }

    int testNumber21 = -130;
    int testNumber22 = 1;
    int testNumberBin21[SIZE] = { 0 };
    int testNumberBin22[SIZE] = { 0 };
    int result2[SIZE] = { 0 };
    convertingDecimalToBinary(testNumber21, testNumberBin21);
    convertingDecimalToBinary(testNumber22, testNumberBin22);
    binaryAddition(testNumberBin21, testNumberBin22, result2);
    if (!(countOnes(result2) == 31 && result2[SIZE - 8] == 0)) {
        printf("ERROR!\nAddition failed on adding negative and positive value\n");
        return false;
    }

    int testNum31 = -510;
    int testNum32 = -3;
    int testNumBin31[SIZE] = { 0 };
    int testNumBin32[SIZE] = { 0 };
    int result3[SIZE] = { 0 };
    convertingDecimalToBinary(testNum31, testNumBin31);
    convertingDecimalToBinary(testNum32, testNumBin32);
    binaryAddition(testNumBin31, testNumBin32, result3);
    if (!(countOnes(result3) == 31 && result3[SIZE - 10] == 0)) {
        printf("ERROR!\nAddition failed on adding two negative values\n");
        return false;
    }
    return true;
}

bool tests() {
    bool testsPassed = true;

    if (!binAdditionTests()) {
        testsPassed = false;
    }

    if (!convertingDecimalToBinTests()) {
        testsPassed = false;
    }

    if (!binaryConvertTests()) {
        testsPassed = false;
    }
    return testsPassed;
}

int main() {
    if (!tests()) {
        return 1;
    }
    int number1 = 0;
    int number2 = 0;
    printf("Enter the first number: ");
    scanf("%d", &number1);
    printf("Enter the second number: ");
    scanf("%d", &number2);
    int binNumber1[SIZE] = { 0 };
    int binNumber2[SIZE] = { 0 };
    convertingDecimalToBinary(number1, binNumber1);
    convertingDecimalToBinary(number2, binNumber2);

    printf("The first number in binary representation: ");
    binOutput(binNumber1);
    printf("\nThe second number in binary representation: ");
    binOutput(binNumber2);

    int result[SIZE] = { 0 };
    binaryAddition(binNumber1, binNumber2, result);

    printf("\nThe sum of both numbers in binary representation: ");
    binOutput(result);

    printf("\nThe sum of the numbers in decimal form: %d", convertingBinaryToDecimal(result));

    return 0;
}