#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *left, *right;
}Node;

Node *newNode(int value){
    Node *root = (Node*)malloc(sizeof(Node));
    root->key = value;
    root->left = root->right = NULL;
    return root;
}

Node *insert(Node *root, int value){
    Node *parent = root;
    Node *temp = newNode(value);

    char direction;

    printf("\nEnter left or right child of %d: ",parent->key);
    if(direction == 'l'){
        if(parent->left == NULL){
            parent->left = temp;
        }else{
            printf("\nNode already exists on the left of %d\n", parent->key);
        }
    }else if(direction == 'r'){
        if(parent->right == NULL){
            parent->right = temp;
        }else{
            printf("Node already exists on the right of %d\n", parent->key);
        }
    }else{
        printf("\nInvalid direction. Node not inserted.\n");
    }
}

Node *inorder(Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}
int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create root\n");
        printf("2. Insert node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (root == NULL) {
                    printf("Enter value for root: ");
                    scanf("%d", &value);
                    root = newNode(value);
                } else {
                    printf("Root already exists.\n");
                }
                break;
            case 2:
                if (root == NULL) {
                    printf("Create the root first.\n");
                } else {
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    insert(root, value);
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
