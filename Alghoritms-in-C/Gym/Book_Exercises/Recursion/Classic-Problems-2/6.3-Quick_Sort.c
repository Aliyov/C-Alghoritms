#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int len){
    for(int i=0; i<len; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++){
        if(arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], )
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex+1, high);
    }
}

int main(){
    int arr[] = {5,1,0,9,6,2,7};
    int len = sizeof(arr)/sizeof(arr[0]);

    printf("\nOriginal array: ");
    printArray(arr, len);

    quickSort(arr, 0, len - 1);

    printf("\nSorted array: ");
    printArray(arr, len);

    return 0;
}