#include <stdio.h>
#include <string.h>
#include "Hash table.h"

#define MODULE 2

int main(void) {
    FILE* file = fopen("file.txt", "r");
    int module = MODULE;
    HashTable* hashTable = createHashTable(MODULE);
    char buffer[256];
    while (!feof(file)) {
        fscanf_s(file, "%s", buffer);
        char* word = (char*)malloc(sizeof(char) * strlen(buffer));
        strcpy(word, buffer);
        hashInsert(hashTable, word, module);
        if (getLoadFactor(hashTable) > 1) {
            hashResize(&hashTable, &module);
            updateLoadFactor(hashTable);
        }
    }
    printWords(hashTable);
    printf("\nThe load factor of the Hash Table is %f\n", getLoadFactor(hashTable));
    printf("The length of the longest list in the hash table is %d\n", findMaxList(hashTable));
    printf("The length of the average list in the hash table is %f\n", findAverageList(hashTable));
    fclose(file);
    return 0;
}