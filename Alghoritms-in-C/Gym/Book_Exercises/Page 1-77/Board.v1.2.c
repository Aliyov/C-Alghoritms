#include <stdio.h>

int main(){
    int r, c, i, n;
    printf("\nEnter number for frame: ");
    scanf("%d",&n);

    for (i=0; i<=n+1; i++){
        printf("-");
    }
    printf("\n");

    for(r=1; r<=n; r++){
        printf("|");
        for(c=1; c<=n; c++){
            if((r%2 == 0 && c%2 == 0) || (r%2 == 1 && c%2 == 1)){
                printf("#");
            }else{
                printf(" ");
            }
        }
        printf("|");
        printf("\n");
    }

    for (i=0; i<=n+1; i++){
        printf("-");
    }
    printf("\n");

    return 0;
}