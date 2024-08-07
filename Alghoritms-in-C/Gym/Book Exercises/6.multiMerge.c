#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(){
    int r, c;
    char **mat;

    FILE *fp = fopen("text.txt", "r");
    fscanf(fp, "%d %d", &r, &c);

    mat = (char**)malloc(r*sizeof(char));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            mat[i] = (char*)malloc(c*sizeof(char));
            fscanf(fp, "%s", mat[i][j]);
        }
    }

    

    return 0;
}