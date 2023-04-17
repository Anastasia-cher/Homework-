#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry {
    char name[50];
    char number[50];
} Entry;

// Adds entries to the file.
void addEntry(Entry entries[], int* entryNumber);

// Outputs recordings to the console.
void outputEntries(Entry entries[], int length);

// Saves data in a file.
void saveEntries(Entry entries[], int length, const char* fileName);

// Reads records from a file.
int readEntries(const char* fileName, Entry entries[]);

// Searches for an entry by name.
const char* findByName(Entry entries[], const char name[], int entryNumber);

// Searches for an entry by number.
const char* findByNumber(Entry entries[], const char number[], int entryNumber);