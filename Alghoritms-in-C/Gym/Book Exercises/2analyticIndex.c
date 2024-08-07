#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 100
#define MAX_LEN 20

typedef struct Word{
    char word[MAX_CHAR];
    int occurances;
    int index;
}Word;

int main(){
    int num,i,n;
    char buffer[256];
    FILE *fp2 = fopen("words.txt","r");
    FILE *fp1 = fopen("text.txt","r");
    fscanf(fp2,"%d",&num);

    Word *words = (Word*)malloc(num *(sizeof(Word)));

    while(i<num && fscanf(fp2, "%s", buffer) != EOF){
        strcpy(words[i].word,buffer);
        words[i].index = 0;
        words[i].occurances = 0;
        i++;
    }

    num = i;

    while(fp2,"%s",buffer)

    return 0;
}