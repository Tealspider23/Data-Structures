#include <stdio.h>
#include <stdlib.h>

//Write a program to implement Red Black tree


// A red black tree is a self balancing binary search tree. It 
// has following properties:
// 1. Every node is either red or black.
// 2. Root is always black.
// 3. There are no two adjacent red nodes.
// 4. Every path from root to NULL has same number of black nodes.

// The idea is to use the concept of BST to store the data and
// use the color property to balance the tree.

// The following code is for the conversion of a binary tree to
// a binary search tree.


typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int color;
}TreeNode;

TreeNode* createNode(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->color = 1;
    return newNode;
}

int compare(const void* a , const void* b){
    return (*(int*)a - *(int*)b);
}

void inorder(TreeNode* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void storeInorder(TreeNode* root , int inorder[], int* index){
    if(root==NULL){
        return;
    }
    storeInorder(root->left , inorder , index);
    inorder[*index]=root->data;
    (*index)++;
    storeInorder(root->right , inorder , index);
}

int countNodes(TreeNode* root){
    if(root==NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

void arrayToBST(int* inorder , TreeNode* root , int* index){
    if(root==NULL)
        return;
    arrayToBST(inorder , root->left , index);
    root->data = inorder[*index];
    (*index)++;
    arrayToBST(inorder , root->right , index);
}

void binaryTreeToBST(TreeNode* root){
    int n = countNodes(root);
    int* inorder = (int*)malloc(sizeof(int)*n);
    int index = 0;
    storeInorder(root , inorder , &index);
    qsort(inorder , n , sizeof(inorder[0]) , compare);
    index = 0;
    arrayToBST(inorder , root , &index);
}

int main(){
    TreeNode* root = createNode(10);
    root->left = createNode(30);
    root->right = createNode(15);
    root->left->left = createNode(20);
    root->right->right = createNode(5);
    inorder(root);
    printf("\n");
    binaryTreeToBST(root);
    inorder(root);
    printf("\n");
    return 0;
}


// Output:
// 20 30 10 15 5
// 5 10 15 20 30
