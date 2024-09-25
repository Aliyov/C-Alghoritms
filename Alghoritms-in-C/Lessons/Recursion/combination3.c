#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 50

typedef struct{
    int num_choice;
    char *choice[MAX_STRING];
}menu_m;


int generate_combo(menu_m *combinations, char **current_combinations, int n, int count, int pos){
    int i;
    if(pos >= n){
        for(i=0; i<n; i++){
            printf("%s ",current_combinations[i]);
        }
        printf("\n");
        return count + 1;
    }

    for(i=0; i<combinations[pos].num_choice; i++){
        current_combinations[pos] = combinations[pos].choice[i];
        count = generate_combo(combinations, current_combinations, n, count, pos+1);
    }
    return count;
}

int main(){
    menu_m combinations[3];

    combinations[0].choice[0] = "A";
    combinations[0].choice[1] = "B";
    combinations[0].choice[2] = "C";
    combinations[0].num_choice = 3;

    combinations[1].choice[0] = "1";
    combinations[1].choice[1] = "2";
    combinations[1].num_choice = 2;

    combinations[2].choice[0] = "A";
    combinations[2].choice[1] = "B";
    combinations[2].choice[2] = "C";
    combinations[0].num_choice = 3;

    int total_combinations;
    char *current_combination[3];
    total_combinations = generate_combi(combinations, current_combination, 3, 0, 0);
    printf("\nTotal: %d", total_combinations);
    return 0;
}