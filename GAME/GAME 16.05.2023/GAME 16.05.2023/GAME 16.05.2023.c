#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LIFE_YES 1
#define LIFE_NO 0

void output(int** array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (array[i][j] == LIFE_YES) {
                printf( " 1 ");
            }
            else {
                printf(" 0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void clear(int** array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = LIFE_NO;
        }
    }
}

int getNeighbor(int** array, int rows, int columns) {
    if (rows < 0 || columns < 0  || array[rows][columns] != LIFE_YES)
    {
        return 0;
    }
    else {
        return 1;
    }
}

int neighborCount(int** array, int rows, int columns) {
    int neighbor = 0;
    neighbor += getNeighbor(array, rows - 1, columns - 1);
    neighbor += getNeighbor(array, rows - 1, columns);
    neighbor += getNeighbor(array, rows - 1, columns + 1);
    neighbor += getNeighbor(array, rows, columns - 1);
    neighbor += getNeighbor(array, rows, columns + 1);
    neighbor += getNeighbor(array, rows + 1, columns - 1);
    neighbor += getNeighbor(array, rows + 1, columns);
    neighbor += getNeighbor(array, rows + 1, columns + 1);

    return neighbor;
}

void game(int** array, int rows, int columns) {
    int** N = (int**)calloc(sizeof(int*), rows);
    for (int k = 0; k < columns; k++) {
        N[k] = (int*)calloc(sizeof(int), columns);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int neighbor = neighborCount(array, i, j);
            if (neighbor == 3) {
                N[i][j] = LIFE_YES;
            }
            else if (neighbor == 2 && array[i][j] == LIFE_YES) {
                N[i][j] = LIFE_YES;
            }
            else {
                N[i][j] = LIFE_NO;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = N[i][j];
        }
    }
}

void input(int** array) {

    array[1][4] = LIFE_YES;
}

int main(int argc, char* argv[]) {
    int rows = 0;
    int columns = 0;
    int colLiveCell = 0;
    printf("Enter the number of rows: ");
    scanf_s("%d", &rows);
    printf("Enter the number of columns: ");
    scanf_s("%d", &columns);
    printf("Enter the number of live cells: ");
    scanf_s("%d", &colLiveCell);
    int** array = (int**)calloc(sizeof(int*), rows);
    for (int k = 0; k < columns; k++) {
        array[k] = (int*)calloc(sizeof(int), columns);
    }
    clear( array, rows, columns);
    input(array);
    output(array, rows, columns);
    for (int i = 0; i < 100000; i++) {
        game(array, rows, columns);
        output(array, rows, columns);
        printf("Generation %d\n", i);
    }
    return 0;
}