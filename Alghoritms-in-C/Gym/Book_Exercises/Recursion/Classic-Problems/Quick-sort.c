// Lomuto version
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot-1);  
        quickSort(arr, pivot+1, high);
    }
}

int main(){
    int arr[] = {8 , 1, 2, 6, 7, 6, 4, 3, 10, 11, 0};
    int len = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, len-1);

    printf("Sorted array: ");
    for(int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}