#include <stdio.h>
#include <stdlib.h>
#include <cmath> 

bool prime(int x) { 
    if (x == 1) {
        return true
    }

    int sqrtNumber = sqrt(x);

    for (int divider = 2; divider <= round(sqrtNumber); ++divider) {
        if (x % divider == 0) {
            return true;
        }
    }

    return false;
}

void main() {
    int maxNumber = 0;
    printf("Enter max number: ");
    scanf_s("%d", &maxNumber);
    printf("\n");
    for (int number = 2; number <= maxNumber; ++number) {
        if (prime(number)) {
            printf("%d\n", number);
        }
    }
    return 0;
}