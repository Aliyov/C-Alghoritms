#include <stdio.h>
#include <string.h>


int main(){
    char word[20];

    printf("Enter word: ");
    scanf("%s", word);

    int size = strlen(word);

    for(int i=0; i<size; i++){
        char temp = word[0];

        for(int j=0; j<size-1; j++){
            word[j] = word[j+1];
        }

        word[size-1] = temp;

        printf("%s\n",word);
    }
    return 0;
}