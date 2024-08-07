#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_ID 3


typedef struct Point{
    float x;
    float y;
    float z;
    int dist;
}Point;

int main(){
    FILE *fp = fopen("words.txt","r");
    if(fp == NULL){
        exit(1);
    }
    int num;

    fscanf(fp,"%d",&num);

    Point *p = (Point *)malloc(num * sizeof(Point));
    int i,dx,dy,dz;
    while(i<num && fscanf(fp,"%f %f %f",&dx, &dy, &dz) != EOF){
        p[i].x = dx;
        p[i].y = dy;
        p[i].z = dz;
        p[i].dist = 0;
        i++;
    }

    num = i;

    int min = 0;

    for(i=0; i<num; i++){
        for(int j=0; j<num; j++){
            dx = p[i].x - p[j].x;
            dy = p[i].y - p[j].y;
            dz = p[i].z - p[j].z;
            p[i].dist = p[i].dist + sqrt(pow(dx,2)+pow(dy,2)+pow(dz,2));
        }
        if(p[i].dist < p[min].dist){
            min = i;
        }
    }

    


    return 0;
}