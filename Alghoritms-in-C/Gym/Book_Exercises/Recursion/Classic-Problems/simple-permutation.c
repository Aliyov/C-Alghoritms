#include <stdio.h>
#include <stdlib.h>

int permute(int arr[], int solution[], int size, int selected, int count, int used[]){
    if(count == selected){
        for(int i=0; i<selected; i++){
            printf("%d ", solution[i]);
        }
        printf("\n");
        return 1;
    }

    int total = 0;
    for(int i=0; i<size; i++){
        if(used[i] != 1){
            solution[count] = arr[i];
            used[i] = 1;
            total += permute(arr, solution, size, selected, count+1, used);
            used[i] = 0;
        }
    }

    return total;
}

int main(){
    int arr[] = {4, 9, 0, 1};
    int size = 4;
    int selected = 4;
    int solution[4];
    int used[4] = {0};

    int total = permute(arr, solution, size, selected, 0, used);

    printf("\nTotal : %d\n\n", total);

    return 0;
}