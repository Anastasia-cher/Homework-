#include <stdio.h>
#include <stdlib.h>

int simple(int x) {
    for (int divider = 2; divider <= x**0.5; ++divider) {
        if ((x % divider) == 0) {
            return 0;
        }
    }
}
void main() {
    int M;
    printf("Enter max number: ");
    scanf_s("%d", &M);
    printf("\n");
    for (int numder = 2; numder <= M; ++numder) {
        if (simple(numder)) {
            printf("%d\n", numder);
        }
    }
}
