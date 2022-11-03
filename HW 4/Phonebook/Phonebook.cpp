#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>



int main() {
    FILE* file;
    struct Entry {
        char name[50];
        char phone[50];
    };

    struct Entry phonebook[100] = { 0 };
    int entriesCounter = 0;

    while (fopen_s(&file, "phonebook.txt", "a")); {
        if (fscanf_s(file, "%[^-]%*c%*c", phonebook[entriesCounter].name) != EOF) {
            const int length = strlen(phonebook[entriesCounter].name);
            phonebook[entriesCounter].name[length - 1] = '\0';
            fscanf_s(file, "%[^\n]%*c", phonebook[entriesCounter].phone);
            entriesCounter++;
        }
    }
    fclose(file);
}

void being() {
    setlocale(LC_ALL, "Rus");
    printf("\nВведите:\n 0 - выйти\n");
    printf(" 1 - добавить запись (имя и телефон)\n");
    printf(" 2 - распечатать все имеющиеся записи\n");
    printf(" 3 - найти номер телефона по имени\n");
    printf(" 4 - найти имя по номеру телефону\n");
    printf(" 5 - сохранить текущие данные\n");
}
