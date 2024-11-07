#include <stdio.h>
#include <stdlib.h>

int arrange(int arr[], int solution[], int size, int selected, int count, int pos){
    if(count == selected){
        for(int i=0; i<selected; i++){
            printf("%d ",solution[i]);
        }
        printf("\n");
        return 1;
    }

    int total = 0;
    for(int i=pos; i<size; i++){
        solution[count] = arr[i];
        total += arrange(arr, solution, size, selected, count+1, i);
    }

    return total;
}

int main(){
    int arr[] = {4, 9, 0, 1};
    int total = 0;
    int size = 4;
    int selected = 4;
    int solution[4];

    total += arrange(arr, solution, size, selected, 0, 0);

    printf("\nTotal: %d\n\n", total);


    return 0;
}

