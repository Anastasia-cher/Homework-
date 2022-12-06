#include <stdio.h>
#include <stdlib.h>
#include <cmath> 

bool prime(int x) { 
    for (int divider = 2; divider <= pow(x, 0.5); ++divider) {
        if (x % divider == 0) {
            return true;
        }
        else {
            return false
        }
    }
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
