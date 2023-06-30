#include <stdio.h>
#include <stdlib.h>


//Diameter of a Binary Tree

//Diameter of the tree is defined as the maximum distance between any two nodes of the tree.

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

int height(Node*root){
    if(root==NULL){
        return 0;
    }
    return 1+ height(root->left) + height(root->right);

}

int max(int a,int b){
    return (a>b)?a:b;
}

int diameter(Node*root){
    if(root==NULL){
        return 0;
    }
    int Lheight=height(root->left);
    int Rheight=height(root->right);
    int Ldiameter=diameter(root->left);
    int Rdiameter=diameter(root->right);

    //return max of the following three
    return max(Lheight+Rheight+1,max(Ldiameter,Rdiameter));
}

int main() {
    Node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    printf("Diameter of the tree is %d\n",diameter(root));
    return 0;
}