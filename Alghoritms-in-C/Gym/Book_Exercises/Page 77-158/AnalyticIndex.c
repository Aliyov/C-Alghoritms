#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define W_SIZE 20

struct Word{
    char word_s[W_SIZE];
    int occurances_s;
};

void processData(struct Word *words, int n, FILE *fp){
    char string[W_SIZE];

    while(fscanf(fp, "%s", string) != EOF){
        for(int i=0; i<n; i++){
            if(strcmp(words[i].word_s, string)==0){
                words[i].occurances_s++;
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%s %d\n",words[i].word_s, words[i].occurances_s);
    }
}

int main(){
    int n;
    char string[W_SIZE];
    struct Word *words;
    FILE *fpTxt = fopen("story.txt","r");
    FILE *fpWords = fopen("words.txt","r");

    fscanf(fpWords, "%d", &n);

    words =(struct Word*) malloc(n * sizeof(struct Word));

    int cnt =0;
    while(fscanf(fpWords, "%s", string) != EOF){
        strcpy(words[cnt].word_s, string);
        words[cnt].occurances_s = 0;
        cnt++;
    }

    processData(words, n, fpTxt);



    return 0;
}