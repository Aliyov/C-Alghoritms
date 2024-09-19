#include <stdio.h>

int main(){
    int n, i, r, c, left, right;
    printf("Enter value: ");
    scanf("%d", &n);

    left = right = n/2;
    
    for(r=0; r<n; r++){
        for(c=0; c<n; c++){
            if(c==left || c==right){
                printf("+");
            }else{
                printf("-");
            }
        }
        if(r<n/2){
            left--;
            right++;
        }else{
            left++;
            right--;
        }
        printf("\n");
    }

    return 0;
}