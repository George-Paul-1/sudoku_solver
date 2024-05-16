#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 9

void print_grid(int grid[SIZE][SIZE], int rows, int columns);
bool possible(int grid[SIZE][SIZE], int x, int y, int n); 
void solve(int grid[SIZE][SIZE], int *solution_found);

int main() {
    static int GRID[SIZE][SIZE];
    int flag = 0;
    int i;
    int j;

    printf("Enter the rows of your Sudoku board - where blank put a 0\n\n");
    
    for (i = 0; i < SIZE; i++) {
        printf("Row: %d\n\n", i+1);
        for (j = 0; j < SIZE; j++) {
            print_grid(GRID, SIZE, SIZE);
            scanf("%d", &GRID[i][j]);
        }
    }

    printf("\nOriginal:\n\n");
    print_grid(GRID, SIZE, SIZE);
    printf("\n");
    solve(GRID, &flag);

    return 0;
}

 void print_grid(int grid[SIZE][SIZE], int rows, int columns) {
    int i;
    int j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
 }

 bool possible(int grid[SIZE][SIZE], int x, int y, int n) {
    int i;
    int j;
    int xO;
    int yO; 

    for (i = 0; i < SIZE; i++) {
        if (grid[y][i] == n) {
            return false;
        }
    }
    for (i = 0; i < SIZE; i++) {
        if (grid[i][x] == n) {
            return false;
        }
    }
    
    xO = (x / 3) * 3;
    yO = (y / 3) * 3;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[yO+i][xO+j] == n) {
                return false;
            }
        }
    }
    return true; 
 }

 void solve(int grid[SIZE][SIZE], int *solution_found) {
    
    int x;
    int y;
    int i;

    for (y = 0; y < 9; y++) {
        for (x = 0; x < 9; x++) {
            if (grid[y][x] == 0) {
                for (i=1; i < 10; i++) {
                    if (possible(grid, x, y, i) == true) {
                        grid[y][x] = i;
                        solve(grid, solution_found);
                        grid[y][x] = 0;
                    }
                }
                return;
            }
        }
    }
    if (*solution_found == 0) {
        printf("SOLUTION:\n\n");
        print_grid(grid, SIZE, SIZE);
        printf("\n");
        *solution_found = 1;
    }
 }
