#include <stdio.h>

int main() {
    int firstValue = 0; 
    int secondValue = 0; 

    printf("Enter the first value: ");
    scanf("%d", &firstValue);
    printf("Enter the second value: ");
    scanf("%d", &secondValue);

    printf("Before the swap: \n");
    printf("The first value: %d\n", firstValue);
    printf("The second value: %d\n", secondValue);

    firstValue = firstValue + secondValue; 
    secondValue = firstValue - secondValue; 
    firstValue = firstValue - secondValue; 

    printf("After the swap: \n");
    printf("The first value: %d\n", firstValue);
    printf("The second value: %d\n", secondValue);

    return 0;
}