#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include "tests.h"
#include "TelephoneDirectory.h"

bool testsFindByName() {
    setlocale(LC_ALL, "Rus");
    Entry test1[5] = { {"Anna", "123456"}, {"Dasha", "987654"}, {"Kolya", "065234"}, {"Lena", "876333"},
                                {"Sasha", "099975"} };
    if (strcmp(findByName(test1, "Kolya", 5), "065234") != 0) {
        printf("����� �� ����� �� ������\n");
        return false;
    }

    Entry test2[5] = { {"Anna", "123456"}, {"Dasha", "987654"}, {"Kolya", "065234"}, {"Lena", "876333"},
                                {"Sasha", "099975"} };
    if (findByName(test2, "Misha", 5) != NULL) {
        printf("����� �� ����� �� ������ � �����, ��� ������ ����� ��� � ���������� �����\n");
        return false;
    }

    Entry test3[5];
    if (findByName(test3, "Kolya", 5) != NULL) {
        printf("����� �� ����� �� ������ � �����, ��� ��� �������\n");
        return false;
    }
    return true;
}

bool testsFindByNumber() {
    setlocale(LC_ALL, "Rus");
    Entry test1[5] = { {"Anna", "123456"}, {"Dasha", "987654"}, {"Kolya", "065234"}, {"Lena", "876333"},
                                {"Sasha", "099975"} };
    if (strcmp(findByNumber(test1, "123456", 5), "Anna") != 0) {
        printf("����� �� ������ �� ������\n");
        return false;
    }

    Entry test2[5] = { {"Anna", "123456"}, {"Dasha", "987654"}, {"Kolya", "065234"}, {"Lena", "876333"},
                                {"Sasha", "099975"} };
    if (findByNumber(test2, "000000", 5) != NULL) {
        printf("����� �� ������ �� ������ � �����, ��� ������ ������ ��� � ���������� �����\n");
        return false;
    }

    Entry test3[5];
    if (findByNumber(test3, "000000", 5) != NULL) {
        printf("����� �� ������ �� ������ � �����, ��� ��� �������\n");
        return false;
    }
    return true;
}

bool tests() {
    if (!testsFindByName()) {
        return false;
    }

    if (!testsFindByNumber()) {
        return false;
    }
    return true;
}