#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int area;
    char name[10];
}rectangle;

int main(){

    FILE *fp = fopen("text.txt","r");
    int numOfRec =0;
    if(fscanf(fp, "%d", &numOfRec) !=1){
        exit(1);
    } 

    rectangle *recs = (rectangle*)malloc(numOfRec*sizeof(rectangle));

    char buffer[256];
    float height;
    float width;
    for(int i=0; i<numOfRec; i++){
        
    }
    while(fscanf(fp,"%s %d %d",recs->name,&height,&width) != 1){

    }

    return 0;
}