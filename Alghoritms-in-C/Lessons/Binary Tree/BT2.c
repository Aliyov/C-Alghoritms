#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;


Node* newNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}


Node* insertNode(Node* root) {
    if (root == NULL) {
        int value;
        printf("\nEnter element for root: ");
        scanf("%d", &value);
        return newNode(value);
    }

    char choice;
    if (root->left == NULL) {
        int value;
        printf("\nEnter left element of %d: ", root->key);
        scanf("%d", &value);
        root->left = newNode(value);
    } else {
        root->left = insertNode(root->left);
    }
    if (root->right == NULL) {
        int value;
        printf("\nEnter right element of %d: ", root->key);
        scanf("%d", &value);
        root->right = newNode(value);
    } else {
        root->right = insertNode(root->right);
    }

    return root;
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice;

    do {
        root = insertNode(root);
        printf("\nDo you want to continue? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice);

    printf("\nInorder traversal of the binary tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
