#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int occurrences;
} index_t;

int main(){
    FILE *fpin = fopen("words.txt","r");
    FILE *fpout = fopen("story.txt","r");

    if((fpin == NULL) && (fpout == NULL)){
        exit(1);
    }

    int wordCount=0;
    if(fscanf(fpin,"%d",&wordCount)!=1){
        exit(1);
    }

    index_t *index = (index_t*)malloc(wordCount*sizeof(index_t));

    for(int i=0; i<wordCount;i++){
        if(fscanf(fpin,"%s",index[i].word)!=1){
            exit(1);
        }
        index[i].occurrences = 0;
    }

    
    return 0;
}