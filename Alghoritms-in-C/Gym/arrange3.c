#include <stdio.h>
#include <stdlib.h>

int generate(char vowels[], char current[], int *mark,int n, int count, int pos){
    if(pos >= n){
        for(int i=0; i<n; i++){
            printf("%c ", current[i]);
        }
        printf("\n");
        return count+1;
    }

    for(int i=0; i<5; i++){
        if(mark[i] == 0){
            mark[i] = 1;
            current[pos] = vowels[i];
            count = generate(vowels,current,mark,n,count,pos+1);
            mark[i] = 0;
        }
    }
    return count;
}

int main(){
    char vowels[] = {'A','E','I','O','U'};
    char current[2];
    int mark[5] = {0};

    int total = generate(vowels,current,mark,2,0,0);
    printf("\nTotal: %d", total);
    return 0;   
}