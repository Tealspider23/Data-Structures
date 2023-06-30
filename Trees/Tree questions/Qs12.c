#include <stdio.h>
#include <stdlib.h>

//WAP to calculate the size of a tree by recursion

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
    return 1+ size(root->left) + size(root->right);
}

int main() {
    Node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    printf("Size of the tree is %d\n",size(root));
    return 0;
}