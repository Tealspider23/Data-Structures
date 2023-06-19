#include <stdio.h>
#include <stdlib.h>

//Insertion and deletion in a Tree 

typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;

 node*newnode(int item){
     node*temp=(node*)malloc(sizeof(node));
     temp->data=item;
     temp->left =NULL;
     temp->right=NULL;
     return temp;
}

node* insert(node*root , int item){
    if(root==NULL){
        return newnode(item);
    }
    if(root->data < item){
        return insert(root->left,item);
    }if(root->data > item){
        return insert(root->right,item);
    }
}



