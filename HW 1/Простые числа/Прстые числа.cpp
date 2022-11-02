#include <stdio.h>
#include <stdlib.h>
#include <cmath> 

bool simple(int x) { 
    for (int divider = 2; divider <= pow(x, 0.5); ++divider) {
        if (x % divider == 0) {
            return 0;
        }
    }
}

void main() {
    int maxNumber;
    printf("Enter max number: ");
    scanf_s("%d", &maxNumber);
    printf("\n");
    for (int numder = 2; numder <= maxNumber; ++numder) {
        if (simple(numder)) {
            printf("%d\n", numder);
        }
    }
}
