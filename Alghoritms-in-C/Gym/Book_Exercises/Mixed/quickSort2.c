#include <stdlib.h>
#include <stdio.h>

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while(start < end){
        while(arr[start] <= pivot && start < end){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }

        if(start < end){
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb], &arr[end]);
    return end;
}

void quickSort(int arr[], int lb, int ub){
    if(lb < ub){
        int loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc-1);
        quickSort(arr, loc+1, ub);
    }
}

int main(){
    int arr[] = {9,4,1,7,6,10,2,5,8,3};
    int size = sizeof(arr)/sizeof(int);

    printf("\nOriginal array: ");
    printArray(arr,size);

    printf("\nSorted array: ");
    quickSort(arr, 0, size);
    printArray(arr,size);
    return 0;
}