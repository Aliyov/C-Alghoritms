#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4;
    int **ptr;

    // Allocate memory for an array of pointers (each representing a row)
    ptr = (int **)malloc(rows * sizeof(int *));
    
    // Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        ptr[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the array
    int count=0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            count++;
            ptr[i][j] = count;
        }
    }

    // Print the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < rows; i++) {
        free(ptr[i]);
    }
    free(ptr);

    return 0;
}
