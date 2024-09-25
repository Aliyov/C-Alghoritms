#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int arr[7];
    int *p;
    p = arr;

    for(int i=0; i<3; i++){
        scanf("%d", arr+i);
    }
    for(int i=0; i<3; i++){
        printf("%d\t", *(arr+i));
    }
    return 0;
}