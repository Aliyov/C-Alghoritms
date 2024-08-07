#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100


void bubbleSort(char **arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){

    char filename[MAX_LENGTH];
    char filename2[MAX_LENGTH];

    printf("Enter first file name: ");
    scanf("%s", filename);
    printf("Enter second file name: ");
    scanf("%s", filename2);

    FILE *fpin = fopen(filename, "r");
    if (fpin == NULL) {
        perror("Can't open the first file");
        exit(1);
    }

    FILE *fpout = fopen(filename2, "w");
    if (fpout == NULL) {
        perror("Can't open the second file");
        fclose(fpin);
        exit(1);
    }

    int numberOfRows;
    fscanf(fpin, "%d", &numberOfRows);

    char **mat = malloc(numberOfRows*sizeof(char*));

    for(int i=0; i<numberOfRows; i++){
        char temp[MAX_LENGTH];
        fscanf(fpin, "%s", temp);

        mat[i] = malloc((strlen(temp) + 1) * sizeof(char));

        strcpy(mat[i], temp);
    }

    bubbleSort(mat, numberOfRows);

    fprintf(fpout, "%d\n", numberOfRows);
    for (int i = 0; i < numberOfRows; i++) {
        fprintf(fpout, "%s\n", mat[i]);
        free(mat[i]); 
    }

    free(mat); 
    fclose(fpin);
    fclose(fpout);
    return 0;
}