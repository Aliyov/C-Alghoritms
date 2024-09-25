#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 20
struct Cordinate{
    float cordinateX;
    float cordinateY;
    float cordinateZ;
    float distance;
};

void swap(struct Cordinate *A, struct Cordinate *B){
    struct Cordinate temp = *A;
    *A = *B;
    *B = temp;
}

int main(){
    float x,y,z;
    char filename[MAX];
    char filename2[MAX];

    struct Cordinate cordinates[MAX];
    printf("\nEnter first filename: ");
    scanf("%s", filename);

    printf("\nEnter second filename: ");
    scanf("%s", filename2);
    
    FILE *fp = fopen(filename, "r");
    FILE *fpOut = fopen(filename2, "w");

    if(fp == NULL || fpOut == NULL){
        printf("Cant open the file ");
        return EXIT_FAILURE;
    }
    int count = 0;
    while(fscanf(fp,"%f%f%f",&x,&y,&z) == 3){
        cordinates[count].cordinateX = x;
        cordinates[count].cordinateY = y;
        cordinates[count].cordinateZ = z;
        cordinates[count].distance = sqrt((x*x) + (y*y) + (y*y));
        count++;
    }

    for(int i=0; i<count; i++){
        for(int j=0; j<count; j++){
            if(cordinates[i].distance > cordinates[j].distance){
                swap(&cordinates[i],&cordinates[j]);
            }
        }
    }

    for(int i=0; i<count; i++){
        fprintf(fpOut, "%.2f %.2f %.2f %.2f\n",cordinates[i].distance,cordinates[i].cordinateX,cordinates[i].cordinateY,cordinates[i].cordinateZ);
    }

    return 0;
}