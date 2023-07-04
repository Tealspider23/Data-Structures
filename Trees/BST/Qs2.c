#include <stdio.h>
#include <stdlib.h>

//Binary Tree to Binary Search tree Conversion

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

