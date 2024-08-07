#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

struct string{
    char *str;
}text_t;


void bubbleSort(struct string arr[],int n);

int main(){
    char filename[MAX_LENGTH];
    char filename2[MAX_LENGTH];

    printf("\nEnter first file name: ");
    scanf("%s",filename);
    printf("\nEnter second file name: ");
    scanf("%s",filename2);
    
    FILE *fpin = fopen(filename,"r");
    if(fpin == NULL){
        perror("\n:::Can open the first file:::\n");
        exit(1);
    }
    
    FILE *fpout = fopen(filename2,"w");
    if(fpout == NULL){
        perror("\n:::Can open the second file:::\n");
        exit(1);
    }
    int numberOfRows;
    fscanf(fpin,"%d",&numberOfRows);

    struct string *buffer = malloc(numberOfRows*sizeof(struct string));


    for(int i=0; i<numberOfRows; i++){
        char temp[MAX_LENGTH];
        fscanf(fpin,"%s",temp);

        buffer[i].str = malloc((strlen(temp)+1)*sizeof(char));
        strcpy(buffer[i].str,temp);
    }

    bubbleSort(buffer,numberOfRows);
    fprintf(fpout,"%d\n",numberOfRows);
    for(int i=0; i<numberOfRows; i++){
        fprintf(fpout,"%s\n",buffer[i].str);
        free(buffer[i].str);
    }

    free(buffer);
    fclose(fpin);
    fclose(fpout);
    return 0;
}

void bubbleSort(struct string arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(strcmp(arr[j].str,arr[j+1].str)>0){
                struct string temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}