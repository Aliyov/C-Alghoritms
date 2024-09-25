#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ID 3+1
#define MAX_NAME 10+1

typedef struct{
    char id[5];
    float x;
    float y;
    float z;
    float dist;
}Cordinate;

int main(){
    int n;
    char name[MAX_NAME];
    float dx, dy, dz;
    Cordinate *points;

    FILE *fpin = fopen("cordinates.txt", "r");
    if(fpin == NULL){
        perror("cant open the file");
        return EXIT_FAILURE;
    }

    fscanf(fpin,"%d",&n);

    points = (Cordinate*) malloc(n*sizeof(Cordinate)); 
    if(points == NULL){
        perror("Cant allocate mem");
        return EXIT_FAILURE;
    }

    int i=0;

    while(i<n && fscanf(fpin, "%f%f%f", &dx, &dy, &dz)!=EOF){
        points[i].x = dx;
        points[i].y = dy;
        points[i].z = dz;
        i++;
    }
    n=i;

    int min = 0;

    for(i=0; i<n; i++){
        for(int j=0;j<n;j++){
            dx = points[i].x - points[j].x;
            dy = points[i].y - points[j].y;
            dz = points[i].z - points[j].z;
            points[i].dist += sqrt(pow(dx,2) + pow(dy,2)+pow(dz,2));
        }

        if(points[i].dist < points[min].dist){
            min = i;
        }
    }

    fprintf(stdout, "Median point: %.2f",points[min].x);
    fprintf(stdout, "%.2f %.2f\n", points[min].y, points[min].z);
    
    free(points);

    return 0;
}