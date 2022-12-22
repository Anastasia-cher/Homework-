#include <stdio.h>
#include <string.h>
#include <locale.h>
#include  "List.h"

void begin() {
    printf("Введите:\n 0 - выйти\n");
    printf(" 1 - добавить значение в сортированный список\n");
    printf(" 2 - удалить значение из списка\n");
    printf(" 3 - распечатать список\n");
}

bool tests() {
    List* testList = createList();
    addValue(testList, 1);
    addValue(testList, 2);
    addValue(testList, 0);
    const bool isSorted = checkSortedList(testList);

    const bool test1Passed = deleteValue(testList, 0);
    const bool test2Passed = deleteValue(testList, 2);
    const bool test3Passed = !deleteValue(testList, 2);
    deleteList(testList);
    return isSorted && test1Passed && test2Passed && test3Passed;
}

int main() {
    setlocale(LC_ALL, "Rus");
    if (!tests()) {
        printf("Ошибка тестирования\n");
        return 1;
    }
    int input = 0;
    bool shouldGoOut = false;
    List* list = createList();
    while (!shouldGoOut) {
        begin();
        scanf_s("%d", &input);
        switch (input) {
        case 0:
            shouldGoOut = true;
            break;
        case 1: {
            printf("\nВведите значение:  ");
            int value = 0;
            scanf_s("%d", &value);
            addValue(list, value);
            printf("\n");
            break;
        }
        case 2: {
            printf("\nВведите значение:  ");
            int value = 0;
            scanf_s("%d", &value);
            if (!deleteValue(list, value))
            {
                printf("Значение не найдено\n");
            }
            printf("\n");
            break;
        }
        case 3:
            if (isEmpty(list)) {
                printf("Список пуст\n\n");
            }
            else {
                printf("\nСписок:  ");
                printList(list);
                printf("\n\n");
            }
            break;
        default:
            printf("Неверный ввод, повторите попытку\n\n");
            break;
        }
    }
    deleteList(list);
    return 0;
}