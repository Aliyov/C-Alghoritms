#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 50

int main(int argc, char *argv[]){
    
    char str1[DIM + 1];
    char str2[DIM + 1];
    char str3[DIM + 1];
    char strOut[DIM * DIM + 1];
    char *start, *end;

    if (argc != 4) {
        printf("\nWrong number of arguments");
        return 1;
    }

    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);
    strcpy(str3, argv[3]);

    strOut[0] = '\0';

    start = str1;

    do{
        end = strstr(start, str2);
        if(end == NULL){
            strcat(strOut, start);
        }else{
            strncat(strOut, start, end-start);
            strcat(strOut, str3);
            start = end + strlen(str2);
        }
    }while(end != NULL);

    printf("%s\n", strOut);

    return 0;
}