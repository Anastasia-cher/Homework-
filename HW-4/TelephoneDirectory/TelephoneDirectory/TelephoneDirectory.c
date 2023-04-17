#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include "TelephoneDirectory.h"

#define STR_LENGTH 50
#define ENTRIES_LENGTH 50

void addEntry(Entry entries[], int* entryNumber) {
    setlocale(LC_ALL, "Rus");
    if (*entryNumber < 49) {
        Entry newEntry = { {'\0'}, {'\0'} };
        char newName[STR_LENGTH] = { '\0' };
        char newNumber[STR_LENGTH] = { '\0' };

        printf("Введите имя: ");
        scanf_s("%s", &newName);
        strcpy(newEntry.name, newName);

        printf("Введите номер: ");
        scanf_s("%s", &newNumber);
        strcpy(newEntry.number, newNumber);

        entries[*entryNumber] = newEntry;
        (*entryNumber)++;

        printf("\n* ГОТОВО *\n");
    }
    else {
        printf("Лимит 50 записей!\n");
    }
}

void outputEntries(Entry entries[], int length) {
    setlocale(LC_ALL, "Rus");
    printf("\n* ВСЕ ЗАПИСИ *\n");

    for (int i = 0; i < length; i++) {
        printf("%s %s\n", entries[i].name, entries[i].number);
    }
}

void saveEntries(Entry entries[], int length, const char* fileName) {
    setlocale(LC_ALL, "Rus");
    FILE* file = fopen(fileName, "w");
    for (int i = 0; i < length; i++) {
        fprintf(file, "%s %s\n", entries[i].name, entries[i].number);
    }
    printf("Сохранение выполнено\n");
    fclose(file);
}

int readEntries(const char* fileName, Entry entries[]) {
    FILE* file = fopen(fileName, "r");
    int i = 0;
    char newName[STR_LENGTH];
    char newNumber[STR_LENGTH];
    while (fscanf(file, "%s", newName) != EOF && fscanf(file, "%s", newNumber) != EOF) {
        strcpy(entries[i].name, newName);
        strcpy(entries[i].number, newNumber);
        i++;
    }
    fclose(file);
    return i;
}

const char* findByName(Entry entries[], const char name[], int entryNumber) {
    for (int i = 0; i < entryNumber; i++) {
        if (strcmp(name, entries[i].name) == 0) {
            return entries[i].number;
        }
    }
    return NULL;
}

const char* findByNumber(Entry entries[], const char number[], int entryNumber) {
    for (int i = 0; i < entryNumber; i++) {
        int result = strcmp(number, entries[i].number);
        if (result == 0) {
            return entries[i].name;
        }
    }
    return NULL;
}