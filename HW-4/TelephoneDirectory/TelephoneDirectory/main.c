#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "tests.h"
#include "TelephoneDirectory.h"

#define STR_LENGTH 50
#define ENTRIES_LENGTH 50

void begin() {
    setlocale(LC_ALL, "Rus");
    printf("\n�������:\n 0 - �����\n");
    printf(" 1 - �������� ������ (��� � �������)\n");
    printf(" 2 - ����������� ��� ��������� ������\n");
    printf(" 3 - ����� ����� �������� �� �����\n");
    printf(" 4 - ����� ��� �� ������ ��������\n");
    printf(" 5 - ��������� ������� ������\n");
}

int main() {
    if (!tests()) {
        return 1;
    }
    setlocale(LC_ALL, "Rus");
    Entry entries[ENTRIES_LENGTH];
    int entryNumber = readEntries("file.txt", entries);
    int option = 0;
    do {
        begin();
        scanf_s("%d", &option);
        switch (option) {
        case 0:
            continue;
        case 1:
            addEntry(entries, &entryNumber);
            break;
        case 2:
            outputEntries(entries, entryNumber);
            break;
        case 3:
            printf("\n������� ���: ");
            char soughtName[STR_LENGTH] = { '\0' };
            scanf_s("%s", soughtName);
            const char* obtainedNumber = findByName(entries, soughtName, entryNumber);
            if (obtainedNumber != NULL) {
                printf("%s - %s\n", soughtName, obtainedNumber);
            }
            else {
                printf("� ���������� ����� ������ �������� ���\n");
            }
            break;
        case 4:
            printf("\n������� �����: ");
            char soughtNumber[STR_LENGTH];
            scanf_s("%s", soughtNumber);
            if (findByNumber(entries, soughtNumber, entryNumber) != NULL) {
                printf("����� %s ����������� %s\n", soughtName, findByNumber(entries, soughtNumber, entryNumber));
            }
            else {
                printf("� ���������� ����� ������ ������ ���\n");
            }
            break;
        case 5:
            saveEntries(entries, entryNumber, "file.txt");
            break;
        }
    } while (option != 0);

    return 0;
}