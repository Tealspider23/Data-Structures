#include <stdio.h>
#include <stdlib.h>

//Symmetric Trees 

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

int isMirror(Node*root1, Node*root2){
    if(root1==NULL && root2==NULL){
        return 1;
    }
    if(root1==NULL || root2==NULL){
        return 0;
    }
    return root1->data==root2->data && isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
}

int isSymmetric(Node*root){
    if(root==NULL){
        return 1;
    }
    return isMirror(root->left,root->right);
}

int main() {
    Node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
