/* 
    Program should able to manipulate an ordered set of integers using dynamic list.
    It has to include functions to perform the following operations:
        
    1. Read an int value from standart input and insert it in the right position. 
        List has to be ordered in ascending order.
    2. Read all int values from standart input and search it in the list printing out a message
        in case of it exists.  
    3. Delete the first element of the list.
    4. Delete the last element of the list.
    5. Read an integer value from standart input, search it in the list and delete it from the list 
        if it exists.
    6. Print-out the ordered set of all integeres stored into the list.
    7. Stop the program.
    All these operations can be selected by the user through a menu.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 20

struct Node{
    int value;
    struct Node *next;
};


void insertElement(struct Node **head, int input){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = input;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode; 
        return;   
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    while(temp != NULL && temp->value < input){
        prev = temp;
        temp = temp->next;
    }

    if(prev == NULL){
        newNode->next = *head;
        *head = newNode;
    }else{
        newNode->next = temp;
        prev->next = newNode;
    }
}

int searchElement(struct Node *head, int input){
    struct Node *temp = head;

    while(temp != NULL){
        if(temp->value == input){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void deleteFirst(struct Node **head){
    if(*head == NULL){
        printf("\nNo element in list.");
        return;
    }
    struct Node *temp = *head;

    *head = (*head)->next;
    free(temp);
}

void deleteLast(struct Node **head){
    struct Node *temp = *head;
    struct Node *prev = NULL;
    
    if(*head == NULL){
        printf("\nList is empty already");
        return;
    }

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    if(prev == NULL){
        free(temp);
        *head = NULL;
    }else{
        prev->next = NULL;
        free(temp);
    }
}

void searchDelete(struct Node **head, int input){
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    while(temp != NULL && temp->value != input){
        prev = temp;
        temp = temp->next;
    }

    if(temp != NULL){
        if(prev == NULL){
            *head = temp->next;
        }else{
            prev->next = temp->next;
        }
        free(temp);
    }

    if(temp->value == input){
        prev->next = temp->next;
        free(temp);
    }else{
        printf("\nElement %d not found in the list", input);
    }
}

void printList(struct Node *head){
    if(head == NULL){
        printf("\nThe list is empty");
        return;
    }

    struct Node *temp = head;

    printf("List: ");
    while(temp != NULL){
        printf("%d ",temp->value);
        temp = temp->next;
    }
}


void user_menu(struct Node **head){
    int choice, value;

    while(1){
        printf("\n\t\t_____Ordered List of Integers_____\n\n");
        printf("1. Insert an element\n");
        printf("2. Search for an element\n");
        printf("3. Delete the first element\n");
        printf("4. Delete the last element\n");
        printf("5. Search and delete an element\n");
        printf("6. Print the list\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter value you want to insert honey:");
                scanf("%d", &value);
                insertElement(head,value);
                break;
            
            case 2:
                printf("\nEnter value for search: ");
                scanf("%d", &value);
                int find = searchElement(*head,value);
                if(find == 1){
                    printf("\n%d is in the list.",value);
                }else{
                    printf("\n%d is not in the list.",value);
                }
                break;

            case 3:
                deleteFirst(head);
                break;
            
            case 4:
                deleteLast(head);
                break;
            
            case 5:
                printf("\nEnter value you want to delete baby");
                scanf("%d", &value);
                searchDelete(head, value);
                break;

            case 6:
                printList(*head);
                break;
            case 7:
                exit(1);
        }
    }
}



int main(int argc, char *argv[]){
    struct Node *head = NULL;
    user_menu(&head);

    return 0;
}
