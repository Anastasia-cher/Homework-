#include <stdio.h>
#include <stdlib.h>

void revers(int array[], int left, int numberOfElements) {
    for (int i = left; i < numberOfElements / 2; i++) {
        int temp = array[i + 1];
        array[i + 1] = array[numberOfElements - i];
        array[numberOfElements - i] = temp;
    }
}
int main() {
    int temp1 = 0;
    int temp2 = 0;
    printf("Enter number of elements 1: ");
    scanf_s("%d", &temp1);
    printf("Enter number of elements 2: ");
    scanf_s("%d", &temp2);
    printf("Enter array: ");
    int array[10000] = {0};
    for (int i = 0; i < temp1 + temp2; i++) {
        scanf_s("%d", &array[i + 1]);
    }
    revers(array, 0, temp1);
    revers(array, temp1, 2 * temp1 + temp2);
    revers(array, 0, temp1 + temp2);
    printf("Inverted array: ");
    for (int i = 0; i < temp1 + temp2; i++) {
        printf("%d ", array[i + 1]);
    }
    return 0;
}

