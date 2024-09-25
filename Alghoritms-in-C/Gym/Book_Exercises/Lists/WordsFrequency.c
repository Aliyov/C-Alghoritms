/*
    Input file stores a story. We should check every word's occurances and print them out with
    ascending order with occurances. 
    We can use multiple approaches. Asked one is list stracture.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 20

typedef struct Node{
    char word[BUFFER_SIZE];
    int counter;
    struct Node *next;
}Node;

void insertWord(struct Node **head, char word[]){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word,word);
    newNode->counter = 1;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
    }else{
        struct Node *current = *head;
        struct Node *prev = NULL;

        while(current != NULL && strcmp(current->word, newNode->word)<0){
            prev = current;
            current = current->next;
        }

        if(prev == NULL){
            newNode->next = *head;
            *head = newNode;
        }else{
            newNode->next = current;
            prev->next = newNode;
        }
    }
}

void checkWord(struct Node **head, char word[]){
    struct Node *temp = *head;

    while(temp != NULL) {
        if(strcmp(temp->word, word) == 0){
            temp->counter++;
            return;
        }
        temp = temp->next;
    }

    insertWord(head,word);
}

void processData(struct Node **head, FILE *in, FILE *out){
    char word[BUFFER_SIZE];
    while(fscanf(in, "%s", word) != EOF){
        for(int i=0; word[i]; i++){
            word[i] = tolower(word[i]);
        }
        checkWord(head,word);
    }
}

void writeData(struct Node *head, FILE *out){
    struct Node *temp = head;
    while(temp != NULL){
        fprintf(out,"%s : %d\n",temp->word, temp->counter);
        temp = temp->next;
    }
}

int main(int argc, char *argv[]){
    char filename1[] = "story.txt";
    char filename2[] = "storyOut.txt";
    FILE *fpIn = fopen(filename1, "r");
    FILE *fpOut = fopen(filename2, "w");

    if(fpIn == NULL || fpOut == NULL){
        perror("\nCan't open the input file");
        return EXIT_FAILURE;
    }

    struct Node *head = NULL;
    processData(&head, fpIn, fpOut);
    writeData(head,fpOut);

    return 0;
}