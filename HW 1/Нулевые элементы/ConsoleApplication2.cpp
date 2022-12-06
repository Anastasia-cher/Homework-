#include <stdio.h>
#include <stdlib.h>

#define size 10

int main() {
    int array[size] = {0};
    int nullElements = 0;

    for (int x = 0; x < size; x++) {
        printf("Enter array elements: mas[%d] = ", x);
        scanf("%d", &array[x]);
    }
    
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            nullElements++;
        }
    }
    printf("\nThe numder of null elements in the array: %d\n", nullElements);
    return 0;
}
