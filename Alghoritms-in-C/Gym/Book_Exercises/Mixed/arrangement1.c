#include <stdio.h>
#include <stdlib.h>

int generate(int *arr, int *current, int *mark,int n, int count, int pos){
    if(pos>=n){
        for(int i=0; i<n; i++){
            printf("%d ",current[i]);
        }
        printf("\n");
        return count+1;
    }

    for(int i=0; i<5; i++){
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
    int val[] = {1,2,3,4,5};
    int current[3];
    int mark[5] = {0};
    int total = generate(val,current,mark,3,0,0);
    printf("\nTotal: %d",total);


    return 0;
}