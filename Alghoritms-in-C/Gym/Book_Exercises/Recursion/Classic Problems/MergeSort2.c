#include <stdio.h>
#include <stdlib.h>



void merge(int arr[], int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for(int i=0; i<n1; i++){
        L[i] = arr[low + i];
    }

    for(int j=0; j<n2; j++){
        R[j] = arr[mid+1+j];
    }

    int i=0;
    int j=0;
    int k=low;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k++] = L[i++];
    }

    while(j<n2){
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int low, int high){
    int mid;

    if(low < high){
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
    return;
}


int main(){
    int arr[] = {9, 6, 4, 10, 1, 5, 0, 12};
    int len = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, len-1);


    printf("Sorted array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}