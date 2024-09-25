#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 500
#define NAME 20
int main(){
    char filename[20];
    char buffer[500];
    int val;
    printf("\nEnter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename,"r");
    int count=0;
    while(fgets(buffer,MAX_LINE_LEN,fp) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';

        count = strlen(buffer);
        
        val = (80 - count)/2;

        for(int i=0; i<val; i++){
            printf(" ");
        }
        printf("%s\n",buffer);

    }

    return 0;
}