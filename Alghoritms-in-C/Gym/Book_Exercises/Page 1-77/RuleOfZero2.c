#include <stdio.h>

int main(){
    int arr[] = {0, 15, 5, 0, 25, 0, 0, 5, 15, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    int newLen=0;

    for(int i=0; i<len; i++){
        if(arr[i] != 0){
            arr[newLen] = arr[i];
            newLen++;
        }
    }

    for(int i=0;i<newLen; i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}