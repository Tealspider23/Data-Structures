#include <stdio.h>
#include <stdlib.h>

//Find the node with least value in a BST

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

TreeNode* insert(TreeNode* root , int data){
    if(root==NULL){
        root = createNode(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left , data);
    }
    else{
        root->right = insert(root->right , data);
    }
    return root;
}

TreeNode* findmin(TreeNode* root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL){
        return root;
    }
    return findmin(root->left);
}

int main(){

    TreeNode* root = NULL;
    root = insert(root , 5);
    root = insert(root , 10);
    root = insert(root , 3);
    root = insert(root , 4);
    root = insert(root , 1);
    root = insert(root , 11);
    root = insert(root , 2);
    root = insert(root , 6);
    root = insert(root , 7);
    root = insert(root , 8);
    root = insert(root , 9);
    TreeNode* min = findmin(root);
    printf("Minimum value in the BST is %d\n" , min->data);
    return 0;
}