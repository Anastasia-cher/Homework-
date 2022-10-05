#include <stdio.h>
#include <stdlib.h>
#include < time.h >


int sortfCountingMethod(int n, int arrayCount[], int sortedArray[]) {
    int k;
    for (int i = 0; i < n; i++) {
        k = 0;
        for (int j = 0; j < n; j++) {
            if (arrayCount[i] > arrayCount[j])
                k++;
        }
        sortedArray[k] = arrayCount[i];
    }
    return sortedArray[k];
}
int main() {
    int N;
    printf("Enter N: ");
    scanf_s("%d", &N);
    //выделение памяти под массивы
    int* array, * sortedArray;
    array = (int*)malloc(N * sizeof(int));
    sortedArray = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        printf("Enter the array elements[%d]: ", i);
        scanf_s("%d", &array[i]);
    }
    //сортировка методом подсчета
    sortfCountingMethod(N, array, sortedArray);
    printf("\nSorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("The array element[%d]: %d\n", i, sortedArray[i]);
    }
}
