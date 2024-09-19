#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(){
    char word[20];
    char **matrix;
    *matrix = (char **)malloc(sizeof(char *)); 
    FILE *fpin = fopen("words.txt", "r");
    while(fscanf(fpin, "%s", word) != EOF){

    }
}

char **input_read(char *name, int *num_ptr){
    char word[20], **strings;
    int n,i;
    FILE *fpin = fopen(name, "r");

    i=0; 
    while(fscanf(fpin,"%s",word)!= EOF){
        i++;
    }

    fclose(fpin);
    n = *num_ptr = i;

    strings = (char **)malloc(n*sizeof(char *));
    
    fpin = fopen(name, "r");

    for(int i=0; i<n; i++){
        fscanf(fpin, "%s", word);
        strings[i] = (char *)malloc(sizeof(strlen(word)+1) * sizeof(char));

        strcpy(strings[i],word);
        fclose(fpin);
    }
}

int main(int argc, char *argv[]){
    char **strings;
    int i, num;
    
    strings = input_read(argv[1], &num);
    
    readFile();

    return 0;
}