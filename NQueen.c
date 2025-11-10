#include <stdio.h>
#include <conio.h>

#define N 4
int board[N][N];
int found = 0; // check if at least one solution exists

void printBoard() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
    found = 1; // mark that solution exists
    getch();   // wait for key press to show each solution
}

int isSafe(int row, int col) {
    int i, j;
    // check left row
    for (i = 0; i < col; i++)
        if (board[row][i]) return 0;

    // check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;

    // check lower-left diagonal
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return 0;

    return 1;
}

void solveNQ(int col) {
    int row;
    if (col == N) {
        printBoard();
        return;
    }

    for (row = 0; row < N; row++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solveNQ(col + 1);
            board[row][col] = 0; // backtrack
        }
    }
}

void main() {
    clrscr();
    solveNQ(0);
    if (!found)
        printf("No solution exists for N = %d\n", N);
    getch();
}
