#include <stdio.h>
#include <stdlib.h>

int main() {
    int dividend = 0;
    int divider = 0;  
    printf("Enter dividend: ");
    scanf_s("%d", &dividend);
    printf("Enter divider (don't enter zero): ");
    scanf_s("%d", &divider);

    while (divider == 0) {
        printf("Zero can't be divider, try again\n");
        printf("Enter divider (don't enter zero): ");
        scanf_s("%d", &divider);
    }
    int answer = 1;
    if (dividend * divider < 0) {
        answer = -1;
        divider = -divider;
    }
    int k = 0;
    while ((dividend - divider * k < 0) || (dividend - divider * k >= abs(divider))) {
        k++;
    }
    printf("Incomplete quotient is %d", k * answer);
    return 0;
}