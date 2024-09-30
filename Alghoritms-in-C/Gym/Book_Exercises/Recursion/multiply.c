#include <stdio.h>
#include <stdlib.h>


void multi(int num){
    if(num <= 0){
        return;
    }

    printf("%d\n", num);
    
    return multi(num-2);
}

int main(){ 
    int num;

    printf("\nEnter number : ");
    scanf("%d", &num);

    multi(num);
    return 0;
}