#include <stdio.h>
#include <stdlib.h>

//Check if given binary tree is a sum tree

// A sum tree is a Binary tree where the root is the sum of its corresponding left and right sub tree 
// and the same is recursively true for all the nodes in the tree.


// A binary tree node
typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;

// Function to create a new node
node*newnode(int value){
    node*temp=(node*)malloc(sizeof(node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to check if the given tree is a sum tree
int isSumTree(node*root){
    //If the tree is empty or has only one node then it is also a sum tree
    if(root==NULL || root->left==NULL && root->right==NULL){
        return 1;
    }
    //Check recursively if the tree is non empty
    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    //If the root is equal to the sum of its left and right subtree then it is a sum tree
    if(root->data == leftsum + rightsum && isSumTree(root->left) && isSumTree(root->right)){
        return 1;
    }
    return 0;

}

// Function to calculate the sum of the tree
int sum(node*root){
    if(root==NULL){
        return 0;
    }
    return sum(root->left) + sum(root->right) +root->data;
}

int main(){


    // Construct the following tree
    //            26
    //         /     \
    //        10      3
    //       /  \    / \
    //      4    6  3   -

    node*root = newnode(26);
    root->left = newnode(10);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(6);
    root->right->right = newnode(3);
    if(isSumTree(root)){
        printf("The given tree is a sum tree");
    }
    else{
        printf("The given tree is not a sum tree");
    }
    return 0;
}