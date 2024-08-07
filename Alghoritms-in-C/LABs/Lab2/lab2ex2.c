#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 20

// Function prototypes
char ***allocate_matrix(int rows, int cols);
void free_matrix(char ***mat, int rows, int cols);
void merge_rows(char ***mat, int rows, int cols, char **result);
void write_output_file(const char *filename, char **array, int total_strings);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];

    FILE *file = fopen(input_filename, "r");
    if (!file) {
        perror("Failed to open input file");
        return 1;
    }

    int rows, cols;
    fscanf(file, "%d %d", &rows, &cols);

    // Allocate memory for the matrix
    char ***matrix = allocate_matrix(rows, cols);

    // Read strings from the file into the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char buffer[MAX_STRING_LENGTH + 1];
            fscanf(file, "%s", buffer);
            matrix[i][j] = strdup(buffer);
        }
    }

    fclose(file);

    // Allocate memory for the merged array
    char **merged_array = (char **)malloc(rows * cols * sizeof(char *));

    // Merge the rows into a single sorted array
    merge_rows(matrix, rows, cols, merged_array);

    // Write the merged array to the output file
    write_output_file(output_filename, merged_array, rows * cols);

    // Free the allocated memory
    free_matrix(matrix, rows, cols);
    for (int i = 0; i < rows * cols; ++i) {
        free(merged_array[i]);
    }
    free(merged_array);

    return 0;
}

// Function to allocate memory for the matrix
char ***allocate_matrix(int rows, int cols) {
    char ***mat = (char ***)malloc(rows * sizeof(char **));
    for (int i = 0; i < rows; ++i) {
        mat[i] = (char **)malloc(cols * sizeof(char *));
    }
    return mat;
}

// Function to free the allocated memory for the matrix
void free_matrix(char ***mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            free(mat[i][j]);
        }
        free(mat[i]);
    }
    free(mat);
}

// Function to merge the sorted rows into a single sorted array
void merge_rows(char ***mat, int rows, int cols, char **result) {
    int *indices = (int *)calloc(rows, sizeof(int));
    int total_strings = rows * cols;
    for (int k = 0; k < total_strings; ++k) {
        char *min_str = NULL;
        int min_row = -1;
        for (int i = 0; i < rows; ++i) {
            if (indices[i] < cols) {
                if (min_str == NULL || strcmp(mat[i][indices[i]], min_str) < 0) {
                    min_str = mat[i][indices[i]];
                    min_row = i;
                }
            }
        }
        result[k] = strdup(min_str);
        indices[min_row]++;
    }
    free(indices);
}

// Function to write the merged array to the output file
void write_output_file(const char *filename, char **array, int total_strings) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open output file");
        exit(1);
    }
    fprintf(file, "%d\n", total_strings);
    for (int i = 0; i < total_strings; ++i) {
        fprintf(file, "%s\n", array[i]);
    }
    fclose(file);
}
