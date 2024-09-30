#include <stdio.h>
#include <stdlib.h>

void rec(int num){
    if(num <= 0){
        return;
    }

    printf("%d\n", num);
    return rec(num-1);
}

int main(){
    int num;
    printf("Simiple sum\n");
    printf("Enter number: ");
    scanf("%d", &num);

    rec(num);

    return 0;
}