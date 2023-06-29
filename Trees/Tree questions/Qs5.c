#include <stdio.h>
#include <stdlib.h>


// Check if removing an edge divides a tree in two halves

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int size(Node*root){
    if(root==NULL){
        return 0;
    }
    return size(root->left)+size(root->right)+1;
}

int check(Node*root, int n){
    if(root==NULL){
        return 0;
    }
    if( size(root)== n-size(root)){
        return 1;
    }
    return check(root->left,n)||check(root->right,n);
    
}

int main() {
    Node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(7);
    root->right->left->left = newNode(2);
    root->right->left->right = newNode(4);
    if (check(root, size(root))) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
