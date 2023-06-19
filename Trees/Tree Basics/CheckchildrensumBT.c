#include <stdio.h>
#include <stdlib.h>

//Check for Children Sum property in a Binary Tree
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

void inorder(node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d \n",root->data);
        inorder(root->right);
    }
}

int isSumproperty(node*node){
  int ldata = 0, rdata = 0;

    if(node==NULL || node->left==NULL && node->right==NULL)
    {
        return 1;
    }else{
        if(node->left!=NULL){
            ldata = node->left->data;
        }
        if(node->right!=NULL){
            rdata=node->right->data;
        }
        if((node->data == ldata + rdata ) && isSumproperty(node->left) && isSumproperty(node->right)){
            return 1;
        }else{
            return 0;
        }

    }
}

 node*insert( node*node,int data){

    if(node==NULL){
        return newnode(data);
    }
    if(data < node->data){
        node->left = insert(node->left,data);
    }
    else if(data > node->data){
        node->right = insert(node->right , data);
    }
    return node;
 }

 node*newnode(int item){
     node*temp=(node*)malloc(sizeof(node));
     temp->data=item;
     temp->left =NULL;
     temp->right=NULL;
     return temp;
}

     int main(){
         int n;
     node*root = NULL;
     root = insert(root ,100);
     printf("The root is 100 \n");
     int choice =1;
     while(choice){
        printf("Enter data :");
        scanf("%d",&n);
        insert(root,n);
        printf("Do you want to enter more nodes (0,1) :");
        scanf("%d",&choice);
     }

     inorder(root);
     }