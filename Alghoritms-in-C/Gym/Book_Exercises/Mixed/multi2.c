#include <stdio.h>
#include <stdlib.h>
#define MAX 20



typedef struct{
    int num_choices;
    char *choice[MAX];
}menu_t;

int generate(menu_t *menus, char *current[], int n, int count, int pos){
    if(pos >= n){
        for(int i=0; i<n; i++){
            printf("%s ",current[i]);
        }
        printf("\n");
        return count+1;
    }

    for(int i=0; i<menus[pos].num_choices; i++){
        current[pos] = menus[pos].choice[i];
        count = generate(menus,current,n,count,pos+1);
    }
    return count;
}

int main(){
    menu_t menus[2];
    menus[0].choice[0] = "Sprite";
    menus[0].choice[1] = "Coca";
    menus[0].choice[2] = "sprite";
    menus[0].num_choices = 3;

    menus[1].choice[0] = "Pasta";
    menus[1].choice[1] = "Cake";
    menus[1].num_choices = 2;
    
    char *current[2];
    int total = generate(menus,current,2,0,0);
    printf("\nTotal: %d",total);


    return 0;
}