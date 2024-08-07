#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **readFile(char *name, int *num2){
    int num, i;
    char **mat;
    char buffer[256];
    
    FILE *fp = fopen(name, "r");
    if(fp == NULL){
        printf("\nError while opening file.");
        exit(1);
    }

    mat = (char **) malloc(num *sizeof(char));

    fscanf(fp, "%d", &num);

    for(int i=0; i<num; i++){
        if(fscanf(fp,"%s",buffer)!=EOF){
            mat[i] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
        }
        strcpy(mat[i],buffer);
    }
    *num2 = num;
    fclose(fp);
    return mat;
}

void printList(char **mat, int num){
    for(int i=0; i<num; i++){
        printf("%s\n", mat[i]);
    }
}

void sortTheList(char **mat,int num){
    for(int i=0; i<num-1; i++){
        for(int j=0; j<num-i-1; j++){
            if(strcmp(mat[j],mat[j+1])>0){
                char *temp = mat[j];
                mat[j] = mat[j+1];
                mat[j+1] = temp;
            }
        }
    }
}

int main(){
    char name[20];
    char **mat;
    int num;
    printf("\nEnter filename: ");
    scanf("%s",name);
    
    mat = readFile(name,&num);
    printf("\nOriginal List:\n");
    printList(mat,num);

    sortTheList(mat,num);

    printf("\nSorted list:\n");
    printList(mat,num);
    return 0;
}