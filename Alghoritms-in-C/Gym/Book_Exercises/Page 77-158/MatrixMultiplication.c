#include <stdio.h>
#include <stdlib.h>

int **readMatrixFile(const char *filename, int *R, int *C) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Cannot open file");
        return NULL;
    }

    // Read rows and columns
    fscanf(fp, "%d%d", R, C);

    // Allocate memory for matrix
    int **matrix = (int **)malloc(*R * sizeof(int *));
    for (int i = 0; i < *R; i++) {
        matrix[i] = (int *)malloc(*C * sizeof(int));
    }

    // Read matrix values
    for (int i = 0; i < *R; i++) {
        for (int j = 0; j < *C; j++) {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }

    fclose(fp);
    return matrix;
}

void multiplyMatrices(int **m1, int **m2, int R1, int C1, int R2, int C2) {
    if (C1 != R2) {
        printf("Matrix multiplication not possible.\n");
        return;
    }

    // Allocate memory for the result matrix
    int **result = (int **)malloc(R1 * sizeof(int *));
    for (int i = 0; i < R1; i++) {
        result[i] = (int *)malloc(C2 * sizeof(int));
    }

    // Perform matrix multiplication
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < C1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // Print the result matrix
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free the memory for result matrix
    for (int i = 0; i < R1; i++) {
        free(result[i]);
    }
    free(result);
}

void freeMatrix(int **matrix, int R) {
    for (int i = 0; i < R; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int R1, C1, R2, C2;
    int **m1 = readMatrixFile("matrix1.txt", &R1, &C1);
    int **m2 = readMatrixFile("matrix2.txt", &R2, &C2);

    if (m1 == NULL || m2 == NULL) {
        return EXIT_FAILURE;
    }

    multiplyMatrices(m1, m2, R1, C1, R2, C2);

    // Free allocated memory
    freeMatrix(m1, R1);
    freeMatrix(m2, R2);

    return 0;
}
