#include <stdio.h>
#include <stdlib.h>

//How to determine if a binary tree is height-balanced?

//A height balanced tree means a tree whose left and right subtrees height differ by at most 1.

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createNode(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int max(int a , int b){
    return (a>b)?a:b;
}

int height(TreeNode* root){
    if(root==NULL)
    return 0;

    return max(height(root->left), height(root->right))+1;
}

int isBalanced(TreeNode* root){
    if(root==NULL){
        return 1;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
        return 1;
    }
    return 0;

}

int main(){

    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(30);
    root->right->left = createNode(15);
    root->right->right = createNode(20);
    if(isBalanced(root)){
        printf("Balanced\n");
    }
    else{
        printf("Not Balanced\n");
    }

    return 0;

}