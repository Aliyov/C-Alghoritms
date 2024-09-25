#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_LEN 21


char ***readFile(int *R, int *C){
    char word[MAX_LEN];
    char ***matrix;
    int r, c;
    FILE *fp = fopen("words.txt","r");
    if (fp == NULL){
        perror("\nFail words.txt cant opened");
        exit(1);
    } 

    fscanf(fp, "%d %d", &r, &c);

    matrix = (char ***)malloc(r * sizeof(char**));
    if(matrix == NULL){
        perror("Allocation error");
        return NULL;
    }

    for(int i=0; i<r; i++){
        matrix[i] = (char **)malloc(c * sizeof(char*));
        if(matrix[i] == NULL){
            perror("Allocation error");
            return NULL;
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            fscanf(fp, "%s", word);
            if((j>0)&&(strcmp(matrix[i][j-1], word)>0)){
                perror("Words in stored file is not sorted in line");
                exit(EXIT_FAILURE);
            }
            matrix[i][j] = strdup(word);
        }
    }

    *R = r;
    *C = c;
    return matrix;
}

char **matrixMerge(char ***matrix, int R, int C) {
    char **array, *min_word;
    int i, j, min_index, *idx;

    // Allocate memory for the merged array and index tracking array
    array = (char**)malloc(R * C * sizeof(char*));
    idx = (int *)calloc(R, sizeof(int));

    i = 0; 
    while (i < R * C) {
        min_index = -1;

        // Find the lexicographically smallest word from the available rows
        for (j = 0; j < R; j++) {
            if (idx[j] < C) { // If there are still words left in row j
                if (min_index == -1 || strcmp(matrix[j][idx[j]], min_word) < 0) {
                    min_index = j;
                    min_word = matrix[j][idx[j]]; 
                }
            }
        }

        // Allocate space for the smallest word and copy it to the merged array
        array[i] = strdup(min_word);
        idx[min_index]++;  // Move to the next word in the chosen row
        i++;
    }

    // Free the index tracking array
    free(idx);

    return array;
}

int main(){
    int R, C;
    char ***matrix;
    char **array;

    matrix = readFile(&R, &C);
    array = matrixMerge(matrix, R, C);
    return 0;
}