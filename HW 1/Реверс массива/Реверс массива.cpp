#include <stdio.h>
#include <stdlib.h>

int main() {
    const int size = 5;
    int array1[size] = { 0 };
    int array2[size] = { 0 };

    for (int x = 0; x < size; x++) {
        printf("Enter array elements: mas[%d] = ", x);
        scanf_s("%d", &array1[x]);
    }

    for (int y = 0; y < size; y++) {
        printf("Enter array elements: mas[%d] = ", y);
        scanf_s("%d", &array2[y]);
    }

    printf("Inverted array: ");

    for (int i = 0; i < size; i++) {
        array1[i] = array1[size - i - 1];
        array2[i] = array2[size - i - 1];
        printf("%d%d", array2[i], array1[i]);
    }
    return 0;
}

