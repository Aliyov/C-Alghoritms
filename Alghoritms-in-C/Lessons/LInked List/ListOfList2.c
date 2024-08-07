#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 20

typedef struct Node{
    char city[MAX_LENGTH];
    char name[MAX_LENGTH];
    char surname[MAX_LENGTH];
    int age;
    struct Node *next;
    struct Node *nextList;
}Node;



int main(){
    FILE *fp = fopen("names.txt", "r");
    if(fp == NULL){
        perror("Cant open the file");
        exit(1);
    }

    int numOfWord;
    fscanf(fp,"%d",&numOfWord);
    
    Node *head = NULL;
    char person_name[MAX_LENGTH];
    char person_surname[MAX_LENGTH];
    char person_city[MAX_LENGTH];
    int person_age;

    for(int i=0; i<numOfWord; i++){
        fscanf(fp, "%s %s %s %d",person_city,person_name,person_surname,&person_age);
        int result = findCity(&head,person_city);
        if(result == 1){
            addPerson(&head, person_city,person_age,person_name,person_surname);
        }
    }


    return 0;
}


