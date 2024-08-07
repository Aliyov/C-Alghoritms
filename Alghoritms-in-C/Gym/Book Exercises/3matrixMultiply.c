#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int **readMatrix(char *filename, int *r, int *c){
    int i,j;
    int **m;
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        exit(1);
    }

    fscanf(fp, "%d %d", r, c);
    m = (int**)malloc((*r)*sizeof(int));

    for(int i=0; i<*r; i++){
        m[i] = (int*)malloc((*c)*sizeof(int));
        for(j=0; j<*c; j++){
            fscanf(fp, "%d", &m[i][j]);
        }
    }
    fclose(fp);

}

int **computeMatrix(int **m1, int **m2, int r1, int r2, int c1, int c2){
    int i, j, k, **m3;
    m3 = (int**)malloc(r1*sizeof(int));
    
}

int main(int argc, char *argv[]){
    int **m1, **m2, **m3;
    int r1,c1,r2,c2;
    scanf("%d",&r1);

    m1 = readMatrix(argv[1], &r1, &c1);
    m2 = readMatrix(argv[2], &r2, &c2);

    m3 = computeMatrix(m1, m2, r1, r2, c1, c2);
    return 0;
}