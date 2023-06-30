#include <stdio.h>
#include <stdlib.h>

//SubTree with given sum in a Binary Tree

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

int isSumTree(Node*root){
    if(root==NULL){
        return 1;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    int sum =0;
    if(root->left!=NULL){
        sum+=root->left->data;
    }
    if(root->right!=NULL){
        sum+=root->right->data;
    }
    return (root->data==sum) && isSumTree(root->left) && isSumTree(root->right);

}

int main() {
    Node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    if (isSumTree(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}