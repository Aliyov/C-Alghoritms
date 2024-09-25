#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(A, B) ((A) > (B) ? (A) : (B))

char **readFile(int *R, int *C) {
    int r, c;
    char ch;
    char **mat;
    FILE *fp = fopen("snakes.txt", "r");
    if (fp == NULL) {
        perror("\nCant open the snakes.txt file");
        exit(1);
    }

    fscanf(fp, "%d %d", &r, &c);
    *R = r;
    *C = c;

    mat = (char**)malloc(r * sizeof(char*));
    if (mat == NULL) {
        perror("\nCant allocate mem for mat");
        exit(1);
    }

    for (int i = 0; i < r; i++) {
        mat[i] = (char*)malloc(c * sizeof(char));
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fscanf(fp, " %c", &ch);
            mat[i][j] = ch;
        }
    }

    fclose(fp);
    return mat;
}

void printMatrix(char **matrix, int R, int C) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

void findSnakeLen(char **matrix, int rowSize, int colSize, int findRow, int findCol) {
    int direction[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    int max_len = 0;

    for (int i = 0; i < 8; i++) {
        int dirRow = direction[i][0];
        int dirCol = direction[i][1];
        int len = 0;

        for (int k = 1;; k++) {
            int newRow = findRow + k * dirRow;
            int newCol = findCol + k * dirCol;

            // Bounds check before accessing matrix
            if (newRow < 0 || newRow >= rowSize || newCol < 0 || newCol >= colSize || matrix[newRow][newCol] != '*') {
                break;
            }

            len++;
            if (len > max_len) {
                max_len = len;
            }
        }
    }

    printf("\nLongest snake size is: %d", max_len);
}

void findSnake(char **matrix, int R, int C) {
    int counterSnake = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == '+') {
                counterSnake++;
                findSnakeLen(matrix, R, C, i, j);
                matrix[i][j] = '.';  // Mark as visited
            }
        }
    }
    printf("\n%d snakes found in file", counterSnake);
}

int main() {
    int R, C;
    char **matrix;
    matrix = readFile(&R, &C);
    printMatrix(matrix, R, C);
    findSnake(matrix, R, C);

    // Free allocated memory
    for (int i = 0; i < R; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
