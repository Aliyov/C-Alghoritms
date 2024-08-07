#include <stdio.h>
#include <stdlib.h>
#define MAX_CHOICES 50

typedef struct{
    int num_choice;
    char *choices[MAX_CHOICES];
}menu_t;

int generate_combination(menu_t *combination, char **current_combination, int n, int count, int pos){
    int i = 0;
    if(pos >= n){
        for(i=0; i<n; i++){
            printf("%s ",current_combination[i]);
        }
        printf("\n");
        return count+1;
    }

    for(i=0; i<combination[pos].num_choice; i++){
        current_combination[pos] = combination[pos].choices[i];
        count = generate_combination(combination, current_combination, n, count, pos+1);
    }
    return count;
}

int main(){
    menu_t combination[3];

    combination[0].choices[0] = "Fanta";
    combination[0].choices[1] = "Coca-Cola";
    combination[0].choices[2] = "Sprite";
    combination[0].num_choice = 3;

    combination[1].choices[0] = "Pizza";
    combination[1].choices[1] = "Burger";
    combination[1].choices[2] = "Doner";
    combination[1].num_choice = 3;

    combination[2].choices[0] = "Cake";
    combination[2].choices[1] = "Tiramisu";
    combination[2].num_choice = 2;


    char *current_combination[3];
    int total_combination = generate_combination(combination, current_combination, 3, 0, 0);
    printf("\nTotal combination: %s",total_combination);

    return 0;
}