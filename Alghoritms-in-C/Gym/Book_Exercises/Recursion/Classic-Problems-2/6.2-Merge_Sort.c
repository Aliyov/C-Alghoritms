#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int len, int sorted){
    if(sorted == 1){
        printf("\nOriginal array: ");
        for(int i=0; i<len; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }else if(sorted == 0){
        printf("\nSorted array: ");
        for(int i=0; i<len; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void partition(int arr[], int left, int right){

}

void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = (int*)malloc(n1 * sizeof(int));
    int *rightArr = (int*)malloc(n2 * sizeof(int));

    for(i=0; i<n1; i++){
        leftArr[i] = arr[left+i];
    }

    for(j=0; j<n2; j++){
        rightArr[j] = arr[mid + j + 1];
    }

    i=0;
    j=0;
    k = left;

    while(i<n1 && j<n2){
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k++] = leftArr[i++];
    }

    while(j<n2){
        arr[k++] = rightArr[j++];
    }

    free(leftArr);
    free(rightArr);
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int arr[] = {5,4,1,9,7,6,0,2};
    int len = sizeof(arr) / sizeof(arr[0]);
    int sorted = 1;
    
    printArray(arr, len, 1);

    mergeSort(arr, 0, len-1);
    
    printArray(arr, len, 0);
    
    return 0;
}