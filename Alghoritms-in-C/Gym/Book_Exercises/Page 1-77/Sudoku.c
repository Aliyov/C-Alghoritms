#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool isValidSudoku(int board[SIZE][SIZE]);
bool isValidRow(int board[SIZE][SIZE], int row);
bool isValidColumn(int board[SIZE][SIZE], int col);
bool isValidBox(int board[SIZE][SIZE], int startRow, int startCol);

int main() {
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (isValidSudoku(board)) {
        printf("The Sudoku board is valid.\n");
    } else {
        printf("The Sudoku board is not valid.\n");
    }

    return 0;
}

// Function to check if the Sudoku board is valid
bool isValidSudoku(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (!isValidRow(board, i) || !isValidColumn(board, i)) {
            return false;
        }
    }
    
    // Check each 3x3 box
    for (int row = 0; row < SIZE; row += 3) {
        for (int col = 0; col < SIZE; col += 3) {
            if (!isValidBox(board, row, col)) {
                return false;
            }
        }
    }
    
    return true;
}

// Function to check if a row is valid
bool isValidRow(int board[SIZE][SIZE], int row) {
    bool seen[SIZE + 1] = { false };
    for (int col = 0; col < SIZE; col++) {
        int num = board[row][col];
        if (num != 0) {
            if (seen[num]) {
                return false;
            }
            seen[num] = true;
        }
    }
    return true;
}

// Function to check if a column is valid
bool isValidColumn(int board[SIZE][SIZE], int col) {
    bool seen[SIZE + 1] = { false };
    for (int row = 0; row < SIZE; row++) {
        int num = board[row][col];
        if (num != 0) {
            if (seen[num]) {
                return false;
            }
            seen[num] = true;
        }
    }
    return true;
}

// Function to check if a 3x3 box is valid
bool isValidBox(int board[SIZE][SIZE], int startRow, int startCol) {
    bool seen[SIZE + 1] = { false };
    for (int row = startRow; row < startRow + 3; row++) {
        for (int col = startCol; col < startCol + 3; col++) {
            int num = board[row][col];
            if (num != 0) {
                if (seen[num]) {
                    return false;
                }
                seen[num] = true;
            }
        }
    }
    return true;
}
