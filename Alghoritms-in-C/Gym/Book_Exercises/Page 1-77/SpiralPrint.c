#include <stdio.h>
#define N 5


int main(){
    int i, j, matrix[N][N];

    /*Input matrix*/
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("Element [%d, %d]: ",i,j);
            scanf("%d\n",&matrix[i][j]);
        }
    }

    /*Print matrix elements*/
    for(i=0; i<N/2; i++){
        /*From left to right*/
        for(j=i; j<N-1-i; j++){
            printf("Element [%d %d]: %d\n", i, j, matrix[i][j]);
        }
        /*From top to buttom*/
        for(j=i; j<N-1-i; j++){
            printf("Element [%d %d]: %d\n", j, N-1-i, matrix[j][N-1-i]);
        }

        /*From right to left*/
        for(j=N-1-i; j>i; j--){
            printf("Element [%d %d]: %d\n", N-1-i, j, matrix[N-1-i][j]);
        }
        
        /*From bottom to top*/
        for(j=N-1-i; j>i; j--){
            printf("Element [%d %d]: %d\n", j, i, matrix[j][i]);
        }
    }

    if(N%2){
        printf("Element [%d %d]: %d\n", N/2, N/2, matrix[N/2][N/2]);
    }


    return 0;
}