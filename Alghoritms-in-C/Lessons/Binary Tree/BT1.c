#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *left, *right;
}Node;



Node *implementation(Node *root){
    if(root == NULL){
        printf("\nEnter value for root: ");
        scanf("%d",&root->key);
    }
}

void insert(Node *root){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        exit(1);
    }

    scanf("%d",&newNode->key);

    root->left = newNode;

}

Node *search(Node *root, int target){
    if(root == NULL)
        return NULL;
    if(root->key == target)
        return root;
    if(root->key > target)
        return root->left;
    if(root->key < target)
        return root->right;
    return root;
}

Node *minimum(Node *root){
    int min;
    if(root == NULL){
        return NULL;
    }else if(root->left == NULL)
        return root;
    else    
        return minimum(root->left);
    
}

Node *insertin(Node* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }

    if (root->key > value) {
        root->left = insertin(root->left, value);
    } else if (root->key < value) {
        root->right = insertin(root->right, value);
    }

    return root;
}


int height(Node *root){
    if(root == NULL){
        return -1;
    }

    int u,v;

    u = height(root->left);
    v = height(root->right);

    if(u>v){
        return (u+1);
    }else{
        return (v+1);
    }

}

int main(){

    Node *root = (Node*)malloc(sizeof(Node));
    root = implementation(root);

    int choice=0;
    while(choice){
        printf("\nEnter value for left child of %d",root->key);
        insert(root);
    }

    return 0;
}