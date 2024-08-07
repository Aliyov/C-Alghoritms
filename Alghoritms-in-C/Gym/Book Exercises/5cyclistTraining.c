#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 20


char **readFile(FILE *fp, int num){
    char **mat;
    mat = (char**)malloc(num*sizeof(char));

    for(int i=0; i<num; i++){
        if(fscanf(fp, "%s %", )
    }
}

int main(){
    int num;
    char **mat;
    char name[20];

    printf("\Enter filename: ");
    scanf("%s",name);
    FILE *fp = fopen(name, "r");
    fscanf(fp, "%d", &num);

    mat = readFile(fp, num);

    return 0;
}