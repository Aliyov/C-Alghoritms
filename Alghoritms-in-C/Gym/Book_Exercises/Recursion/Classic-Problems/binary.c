#include <stdio.h>
#include <stdlib.h>

void generate(int n, int *arr, int index){
    if(index == n){
        for(int i=0; i<n; i++){
            printf("%d", arr[i]);
        }
        printf("\n");
        return;
    }

    arr[index] = 0;
    generate(n, arr, index+1);

    arr[index] = 1;
    generate(n, arr, index+1);
}

int main(){
    int n;
    printf("\nEnter the number of bits: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int));
    
    generate(n, arr, 0);
    free(arr);
    return 0;
}