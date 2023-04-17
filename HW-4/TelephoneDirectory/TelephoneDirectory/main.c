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
    printf("\nВведите:\n 0 - выйти\n");
    printf(" 1 - добавить запись (имя и телефон)\n");
    printf(" 2 - распечатать все имеющиеся записи\n");
    printf(" 3 - найти номер телефона по имени\n");
    printf(" 4 - найти имя по номеру телефону\n");
    printf(" 5 - сохранить текущие данные\n");
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
            printf("\nВведите имя: ");
            char soughtName[STR_LENGTH] = { '\0' };
            scanf_s("%s", soughtName);
            const char* obtainedNumber = findByName(entries, soughtName, entryNumber);
            if (obtainedNumber != NULL) {
                printf("%s - %s\n", soughtName, obtainedNumber);
            }
            else {
                printf("В телефонной книге такого человека нет\n");
            }
            break;
        case 4:
            printf("\nВведите номер: ");
            char soughtNumber[STR_LENGTH];
            scanf_s("%s", soughtNumber);
            if (findByNumber(entries, soughtNumber, entryNumber) != NULL) {
                printf("Номер %s принадлежит %s\n", soughtName, findByNumber(entries, soughtNumber, entryNumber));
            }
            else {
                printf("В телефонной книге такого номера нет\n");
            }
            break;
        case 5:
            saveEntries(entries, entryNumber, "file.txt");
            break;
        }
    } while (option != 0);

    return 0;
}