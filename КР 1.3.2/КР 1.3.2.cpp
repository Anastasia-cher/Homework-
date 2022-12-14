#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

struct Numbers {
    int number[100];
};


void being() {
    setlocale(LC_ALL, "Rus");
    printf("\nВведите:\n 0 - выйти\n");
    printf(" 1 – ввести число;\n");
    printf(" 2 – распечатать пять самых больших из введённых до сих пор чисел.\n");
}

void addNumber(Numbers entries[], int& amountOfEntriesInBuffer) {
    if (amountOfEntriesInBuffer < 100) {
        printf("\nВведите число: ");
        scanf_s("%d", entries[amountOfEntriesInBuffer].number);
        ++amountOfEntriesInBuffer;
    }
    else {
        printf("В базе данных недостаточно место\n");
    }
}

void printNumbers(Numbers entries[], int& amountOfEntriesInBuffer) {
    if (amountOfEntriesInBuffer == 0) {
        printf("Записей нет\n");
    }
    else {
        int* max = 0;
        for (int i = 0; i < amountOfEntriesInBuffer; ++i) {
            if (entries[amountOfEntriesInBuffer].number > max) {
                max = entries[amountOfEntriesInBuffer].number;
            }
        }
        for (int i = 0; i < 5; ++i) {
            printf("%d", entries[amountOfEntriesInBuffer].number);
        }
    }
}

int main() {
    being();
    int amountOfEntriesInBuffer = 0;
    int N = 0;
    scanf_s("%d", &N);
    switch (N) {
    case 0:
        break;
    case 1:
        addNumber(number[100], amountOfEntriesInBuffer);
        break;
    default:
        printNumbers(number[100], amountOfEntriesInBuffer);
            break;
    }
    return 0;
}