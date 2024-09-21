#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 20 


void printMatrix(char ***matrix, int R, int C){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            printf("%s ", matrix[i][j]);
        }

        printf("\n");
    }
}
char ***readFile(int *R, int *C){
    int r, c;
    char word[MAX_LINE];
    char ***matrix;

    FILE *fp = fopen("words2.txt", "r");
    if(fp == NULL){
        perror("\nCant open the file\n");
        exit(1);
    }
    
    fscanf(fp, "%d %d", &r, &c);
    *R = r;
    *C = c;

    matrix = (char***)malloc(r * sizeof(char**));

    if(matrix == NULL){
        perror("\nCant allocate mem for matrix\n");
        return NULL;
    }


    for(int i=0; i<r; i++){
        matrix[i] = (char**)malloc(c * sizeof(char*));
        if(matrix[i] == NULL){
            perror("\nCant allocate mem for matrix elements\n");
            return NULL;
        }
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            fscanf(fp, "%s", word);
            if((j>0) && (strcmp(matrix[i][j-1],word)>0)){
                perror("\nWords in the matrix is not alphabetically ordered.\n");
                exit(1);
            }
            matrix[i][j] = strdup(word);
        }
    }
    return matrix;
}



char **multiMerge(char ***matrix, int R, int C) {
    char **array;
    char min_word[MAX_LINE];
    int min_row;
    int total_words = R * C;
    int cnt = 0;
    int *index;

    index = (int *)calloc(R, sizeof(int)); 
    array = (char **)malloc(total_words * sizeof(char *));
    
    while (cnt < total_words) {
        min_row = -1;
        strcpy(min_word, "zzzzzzzz");  

        for (int i = 0; i < R; i++) {
            if (index[i] < C && strcmp(matrix[i][index[i]], min_word) < 0) {
                strcpy(min_word, matrix[i][index[i]]);
                min_row = i;
            }
        }

        array[cnt] = strdup(min_word);

        index[min_row]++;
        cnt++;  
    }

    free(index);  
    return array;  
}

void printArray(char **array, int R, int C){
    for(int i=0; i<R*C; i++){
        printf("%s\n", array[i]);
    }
}

int main(){
    int R, C;
    char ***matrix;
    char **array;

    matrix = readFile(&R, &C);
    array = multiMerge(matrix, R, C);
    //printMatrix(matrix, R, C);
    printArray(array,R,C);
    return 0;
}

