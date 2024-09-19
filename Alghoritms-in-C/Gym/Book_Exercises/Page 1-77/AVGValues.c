#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 3

int valid(int i, int j){
    if(i>=0 && i<MAX && j>=0 && j<MAX){
        return 1;
    }else{
        return 0;
    }
}

double avarage(double matrixIn[MAX][MAX],int R, int C){
    int count=0;
    double sum=0.0;

    for(int i=R-1; i<=R+1; i++){
        for(int j=C-1; j<=C+1; j++){
            if(valid(i,j) && !(i==R && j==C)){
                sum = sum + matrixIn[i][j];
                count++;
            }
        }
    }
    sum = sum/count;
    return sum;
    
}

int main(){
    int R, C;
    double matrixIn[MAX][MAX];
    double matrixOut[MAX][MAX];

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            scanf("%lf",&matrixIn[i][j]);
        }
    }

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            matrixOut[i][j] = avarage(matrixIn, i, j);
        }
    }

    printf("\nMatrix with averaged adjacent elements:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%.2lf ", matrixOut[i][j]);
        }
        printf("\n");
    }



    return 0;
}