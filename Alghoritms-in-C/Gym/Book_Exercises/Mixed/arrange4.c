#include <stdio.h>
#include <stdlib.h>

int generate(char vowels[], char current[], int n, int count, int pos){
    if(pos >= n){
        for(int i=0; i<n; i++){
            printf("%c ", current[i]);
        }
        printf("\n");
        return count+1;
    }

    for(int i=0; i<5; i++){
        current[pos] = vowels[i];
        count = generate(vowels,current,n,count,pos+1);
    }
    return count;
}

int main(){
    char vowels[] = {'A','E','I','O','U'};
    char current[2];

    int total = generate(vowels,current,2,0,0);
    printf("\nTotal: %d", total);
    return 0;   
}