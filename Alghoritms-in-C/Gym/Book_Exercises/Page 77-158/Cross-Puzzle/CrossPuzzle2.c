#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 20

void printMatrix(char **matrix, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printWords(char **words, int num) {
    for (int i = 0; i < num; i++) {
        printf("%s\n", words[i]);
    }
}

char **readFile(int *R, int *C) {
    int r, c;
    char **matrix;
    FILE *fp = fopen("puzzle.txt", "r");
    if (fp == NULL) {
        perror("Can't open puzzle.txt");
        exit(1);
    }

    fscanf(fp, "%d %d", &r, &c);
    *R = r;
    *C = c;

    matrix = (char **)malloc(r * sizeof(char *));
    if (matrix == NULL) {
        perror("Can't allocate memory for matrix");
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < r; i++) {
        matrix[i] = (char *)malloc(c * sizeof(char));
        if (matrix[i] == NULL) {
            perror("Can't allocate memory for matrix elements");
            fclose(fp);
            return NULL;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fscanf(fp, " %c", &matrix[i][j]);
        }
    }
    fclose(fp);
    return matrix;
}

char **readWords(int *number) {
    char **words;
    char buffer[BUFFER_SIZE];
    int counter;

    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        perror("Can't open words.txt");
        exit(1);
    }

    fscanf(fp, "%d", &counter);
    *number = counter;

    words = (char **)malloc(counter * sizeof(char *));
    if (words == NULL) {
        perror("Can't allocate memory for words");
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < counter; i++) {
        fscanf(fp, "%s", buffer);
        words[i] = strdup(buffer);
    }

    fclose(fp);
    return words;
}

void checkPossibilities(char **matrix, char **words, int row, int col, int k, int R, int C) {
    char *word = words[k];
    int wordLength = strlen(word);

    // Directions: (row change, column change)
    int directions[8][2] = {
        {-1, 0},  // Up
        {1, 0},   // Down
        {0, -1},  // Left
        {0, 1},   // Right
        {-1, -1}, // Up-Left
        {-1, 1},  // Up-Right
        {1, -1},  // Down-Left
        {1, 1}    // Down-Right
    };

    for (int d = 0; d < 8; d++) {
        int dirRow = directions[d][0];
        int dirCol = directions[d][1];
        int found = 1;

        for (int l = 0; l < wordLength; l++) {
            int newRow = row + l * dirRow;
            int newCol = col + l * dirCol;

            // Check if out of bounds or character doesn't match
            if (newRow < 0 || newRow >= R || newCol < 0 || newCol >= C || matrix[newRow][newCol] != word[l]) {
                found = 0;
                break;
            }
        }

        if (found) {
            printf("Found word '%s' starting at (%d, %d) in direction (%d, %d)\n", word, row, col, dirRow, dirCol);
        }
    }
}

void process(char **matrix, char **words, int R, int C, int numberOfWords) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < numberOfWords; k++) {
                if (matrix[i][j] == words[k][0]) { // Compare first character
                    checkPossibilities(matrix, words, i, j, k, R, C);
                }
            }
        }
    }
}

void freeMemory(char **matrix, char **words, int R, int numberOfWords) {
    for (int i = 0; i < R; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < numberOfWords; i++) {
        free(words[i]);
    }
    free(words);
}

int main() {
    char **matrix, **words;
    int numberOfWords, R, C;

    matrix = readFile(&R, &C);
    words = readWords(&numberOfWords);
    process(matrix, words, R, C, numberOfWords);

    //printMatrix(matrix, R, C);
    //printWords(words, numberOfWords);

    freeMemory(matrix, words, R, numberOfWords);
    return 0;
}
