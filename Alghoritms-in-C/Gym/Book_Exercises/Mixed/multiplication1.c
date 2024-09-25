#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct{
    int num_choice;
    int choice[MAX];
}hint_h;

int generate(hint_h *puzzle, int *current_hint,int n, int count, int pos){
    int i;

    if(pos>=n){
        for(int i=0; i<n; i++){
            printf("%d ",current_hint[i]);
        }
        printf("\n");
        return count+1;
    }

    for(i=0; i<puzzle[pos].num_choice; i++){
        current_hint[pos] = puzzle[pos].choice[i];
        count = generate(puzzle,current_hint,2,count,pos+1);
    }
    return count;
}

int main(){
    hint_h puzzle[2];
    
    puzzle[0].choice[0] = 1;
    puzzle[0].choice[1] = 2;    
    puzzle[0].choice[2] = 3;
    puzzle[0].choice[3] = 4;
    puzzle[0].num_choice = 4;

    puzzle[1].choice[0] = 1;
    puzzle[1].choice[1] = 2;
    puzzle[1].choice[2] = 3;
    puzzle[1].num_choice = 3;

    int total_number;
    int *current_hint;

    total_number = generate(puzzle,current_hint,2,0,0);
    printf("\nTotal number: %d",total_number);
    return 0;
}