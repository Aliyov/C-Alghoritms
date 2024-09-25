#include <stdio.h>
#include <stdlib.h>


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int lb, int mid, int ub){
    int size = ub - lb + 1;
    int *b = (int*)malloc(size * sizeof(int));
    int i = lb;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            b[k++] = arr[i++];
        }else{
            b[k++] = arr[j++];
        }
    }

    while(i<=mid){
        b[k++] = arr[i++];
    }
    while(j<=ub){
        b[k++] = arr[j++];
    }

    for(int z=0; z<size; z++){
        arr[lb+z] = b[z];
    }
    free(b);
}

void mergeSort(int arr[], int lb, int ub){
    if(lb >= ub){
        return;
    }

    int mid = (lb + ub)/2;
    mergeSort(arr,lb,mid);
    mergeSort(arr,mid+1,ub);
    merge(arr, lb, mid, ub);
}


int main(){
    int arr[] = {6, 5, 3, 1, 9, 4, 2};
    int size = sizeof(arr) / sizeof(int);

    printf("\nOriginal array: ");
    printArray(arr,size);

    mergeSort(arr, 0, size-1);
    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}