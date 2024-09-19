#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **malloc2d(int r, int c){
    int i,j;
    char **mat;

    mat = (char**)malloc(r*sizeof(char *));
    for(int i=0; )
}


int main(int argc, char *argv[]){
    char **matrixIn, **matrixOut;
    int *word;
    int i,j,R,C;
    FILE *fp;

    fp = fopen(argv[1], "r");
    fscanf(fp,"%d %d", &R, &C);
    matrixIn = malloc2d(R,C);
    matrixOut = malloc2d(R,C);

    word = (char*)malloc((max(R,C)+1) * sizeof(char));

    return 0;
}