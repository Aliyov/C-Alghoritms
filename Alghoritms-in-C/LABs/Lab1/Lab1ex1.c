#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORD_LENGTH 15
#define MAX_WORDS 100 

typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int occurrences;
  } index_t;

int main(){
    FILE *fp = fopen("selectedWord.txt","r");
    FILE *fout = fopen("story.txt","r");

    if (fp == NULL) {
        perror("Can't open selected word list file!");
        exit(1);
    }

    if (fout == NULL) {
        perror("Can't open story file!");
        fclose(fp);
        exit(1);
    }

    int wordCount=0;
    if(fscanf(fp,"%d",&wordCount)!=1){
        perror("Fail to read");
        fclose(fp);
        fclose(fout);
        exit(1);
    }

    index_t *index = (index_t*)malloc(wordCount*sizeof(index_t));
    if(index == NULL){
        fclose(fp);
        fclose(fout);
        exit(1);
    }

    for(int i=0; i<wordCount; i++){
        if(fscanf(fp,"%s",index[i].word) != 1){
            exit(1);
        }
        index[i].occurrences=0;
    }

    char buffer[MAX_WORD_LENGTH+1];
    while(fscanf(fout,"%s",buffer) != EOF){
        for(int i=0;i<wordCount;i++){
            if(strcmp(buffer,index[i].word)==0){
                index[i].occurrences++;
            }
        }
    }
    printf("Word occurances:");
    for(int i=0; i<wordCount; i++){
        printf("%s: %d\n",index[i].word,index[i].occurrences);
    }

    free(index);
    fclose(fp);
    fclose(fout);
    return 0;
}