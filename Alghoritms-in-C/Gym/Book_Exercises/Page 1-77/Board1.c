#include <stdio.h>
#include <string.h>

int main(){
    int n, r, c;
    printf("\nNumber of frames: ");
    scanf("%d",&n);

    /*First line*/
    r=0;
    while(r<=n+1){
        printf("-");
        r++;
    }
    printf("\n");

    r=1;

    while(r<=n){
        printf("|");
        c=1;
        while(c<=n){
            /*Check element odd on odd rows and even even rows*/
            if((r%2==1 && c%2==1) || (r%2==0 && c%2==0)){
                printf("#");
            }else{
                printf(" ");
            }
            c++;
        }
        printf("|\n");
        r++;
    }

    /*Last line*/
    r=0;
    while(r<=n+1){
        printf("-");
        r++;
    }
    printf("\n");

    return 0;
}