#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int key;
	struct Node *next;
}Node;


void list(struct Node **head, int value){
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->next = NULL;
	newNode->key = value;

	if(*head == NULL){
		*head = newNode;
		return;
	}

	struct Node *temp = *head;

	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = newNode;
}

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->key);
        temp = temp->next;
    }
    printf("NULL\n");
}


void listT(struct Node *head){
	if(head == NULL){
		return;
	}
	
	printf("%d -> ",head->key);
	listT(head->next);
}


void listH(struct Node *head){
	if(head == NULL){
		return;
	}
	
	listH(head->next);
	printf("%d -> ", head->key);
}

int main(){
	int cont=1;
	int value;
	struct Node *head = NULL;
	
	while(cont){
		printf("Enter list value: ");
		scanf("%d", &value);
		list(&head, value);
		printf("\nContinue : ");
		scanf("%d", &cont);
	}
	printf("\nThe list: ");
	listH(head);
		

	return 0;
}
