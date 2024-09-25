#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char word[100];
    printf("\nEnter word: ");
    scanf("%99s",word);


    char *p;
    p = (char*)malloc((strlen(word)+1)*sizeof(char));
    if(p == NULL){
        printf("allcoation error");
        exit(1);
    }

    for(int i=0; word[i] != '\0'; i++){
        p[i] = word[i];
    }

    p[strlen(word)] = '\0';
    printf("\nCopied string: %s",p);
    free(p);
    return 0;
}