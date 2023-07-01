#include <stdio.h>
#include <stdlib.h>

//Iterative searching in Binary Search tree

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* newTreeNode(int value){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

TreeNode* insert(TreeNode* root, int value){
    if(root==NULL){
        return newTreeNode(value);
    }
    if(value<root->data){
        root->left = insert(root->left,value);
    }
    else{
        root->right = insert(root->right,value);
    }
    return root;
}

void printTree(TreeNode* root){
    if(root==NULL){
        return;
    }
    printTree(root->left);
    printf("%d ",root->data);
    printTree(root->right);
}

TreeNode* search(TreeNode*root , int value){
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL){
        if(root->data==value){
            return root;
        }
        else if(root->data>value){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
        
    }

int main(){
    TreeNode* root = NULL;
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,15);
    root = insert(root,7);
    root = insert(root,12);
    root = insert(root,20);
    printTree(root);
    printf("\n");
    TreeNode* temp = search(root,7);
    if(temp!=NULL){
        printf("Found\n");
    }
    else{
        printf("Not Found\n");
    }
    return 0;
}