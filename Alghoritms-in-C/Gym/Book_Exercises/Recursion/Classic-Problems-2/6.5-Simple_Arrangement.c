#include <stdio.h>
#include <stdlib.h>


void arrange(int arr[], int n, int solution[], int pos, int used[]){
    if(pos >= n){
        printf("{");
        for(int i=0; i<n; i++){
            printf("%d ", solution[i]);
        }
        printf("}\n");
        return;
    }

    for(int i=0; i<4; i++){
        if(used[i] != 1){
            solution[pos] = arr[i];
            used[i] = 1;
            arrange(arr, n, solution, pos+1, used);
            used[i] = 0;
        }
    }
}

int main(){
    int arr[] = {4,9,1,0};
    int n = 2;
    int solution[2];
    int used[4] = {0};

    arrange(arr, n, solution, 0, used);

    return 0;
}