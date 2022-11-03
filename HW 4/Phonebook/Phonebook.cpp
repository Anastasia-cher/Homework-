#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

struct Book {
    char name[50];
    char phone[50];
};

int countEntriesInBuffer(Book entries[], char const fileName[]) {
	FILE* file = fopen(fileName, "a");
	int entriesCounter = 0;
	while (!feof(file)) {
		if (fscanf_s(file, "%[^-]%*c%*c", entries[entriesCounter].name) != EOF) {
			const int length = strlen(entries[entriesCounter].name);
			entries[entriesCounter].name[length - 1] = '\0';
			fscanf_s(file, "%[^\n]%*c", entries[entriesCounter].phone);
			++entriesCounter;
		}
	}
	fclose(file);
	return entriesCounter;
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

void addEntry(Book entries[], int &amountOfEntriesInBuffer) {
	if (amountOfEntriesInBuffer < 100) {
		printf("Введите имя: ");
		scanf_s("\n%[^\n]", entries[amountOfEntriesInBuffer].name);
		printf("Введите номер телефона: ");
		scanf_s("\n%[^\n]", entries[amountOfEntriesInBuffer].phone);
		++amountOfEntriesInBuffer;
	}
	else {
		printf("В базе данных недостаточно место\n");
	}
}

void printAllEntries(Book entries[], int amountOfEntriesInBuffer) {
	if (amountOfEntriesInBuffer == 0) {
		printf("Записей нет\n");
	}
	else {
		for (int i = 0; i < amountOfEntriesInBuffer; ++i) {
			printf("%s - %s\n", entries[i].name, entries[i].phone);
		}
	}
}
