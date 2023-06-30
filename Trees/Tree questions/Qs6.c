#include <stdio.h>
#include <stdlib.h>

//Check whether a Binary tree is perfect or not

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

int depth(Node*root){
    int g =0;
    while(root!=NULL){
        g++;
        root=root->left;
    }
    return g;
}

int isPerfect(Node*root , int d , int level){
     if(root==NULL){
        return 1;
     }
     if(root->left==NULL && root->right==NULL){
        return d==level+1;
     }
     if(root->left==NULL || root->right==NULL){
        return 0;
     }
     return isPerfect(root->left,d,level+1) && isPerfect(root->right,d,level+1);
}

int main() {
    Node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    int d = depth(root);
    if (isPerfect(root,d,0)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}