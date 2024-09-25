#include <stdio.h>
#include <stdlib.h>


int generate(int arr[], int *current, int *mark, int n, int count, int pos){
    if(pos >= n){
        for(int i=0; i<n; i++){
            printf("%d ", current[i]);
        }
        printf("\n");
        return count+1;
    }

    for(int i=0; i<4; i++){
        if(mark[i] == 0){
            mark[i] = 1;
            current[pos] = arr[i];
            count = generate(arr,current,mark,n,count,pos+1); 
            mark[i] = 0;
        }
    }
    return count;
}

int main(){
    int arr[] = {4,9,1,0};
    int size = sizeof(arr)/sizeof(int);

    int current[2];
    int mark[4] = {0};
    int total = generate(arr,current,mark,2,0,0);
    
    printf("\nTotal: %d\n", total);
    
    return 0;
}