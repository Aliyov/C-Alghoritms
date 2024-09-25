#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME 20
#define SIZE 20

int main(){
    char filename[NAME];
    char filename2[NAME];
    char word[SIZE];
    char ch;

    FILE *fpIn, *fpOut;

    
    printf("\nEnter input filename: ");
    scanf("%s", filename);
    printf("\nEnter output filename: ");
    scanf("%s",filename2);
    fpIn = fopen(filename,"r");
    fpOut = fopen(filename2,"w");
    
    int blank = 0;
    int i=0;
    while(fscanf(fpIn,"%c", &ch)!= EOF){
        if(ch != '\n'){
            if(ch == ' '){
                blank = 1;
            }else{
                if(blank){
                    ch = toupper(ch);
                    blank=0;
                }
                fprintf(fpOut,"%c",ch);
                i++;

                if(i == 20){
                    fprintf(fpOut,"\n");
                    i=0;
                }
            }
        }    
    }
    if(i !=0 ){
        fprintf(fpOut,"\n");
    }
    
    fclose(fpIn);
    fclose(fpOut);
    
    return 0;
}