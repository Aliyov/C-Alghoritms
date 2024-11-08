#include <stdio.h>
#include <stdlib.h>

void combi(int arr[], int solution[], int n, int solutionSize, int pos, int start){
    if(pos == solutionSize){
        for(int i=0; i<solutionSize; i++){
            printf("%d ", solution[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i=start; i<n; i++){
        solution[pos] = arr[i];
        combi(arr, solution, n, solutionSize, pos+1, i);
    }
}

int main(){
    int arr[] = {1,2,3,4};
    int solution[2];
    int n = 4;
    int solutionSize = 2;
    combi(arr, solution, n, solutionSize, 0, 0);

    return 0;
}