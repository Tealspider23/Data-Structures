#include <stdio.h>
#include <stdlib.h>

//Searching in a Binary search Tree
typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;


 node*search(node*root , int value){
    if(root==NULL || root->data==value){
        return root;
    }
    if(root->data<value){
        return search(root->right,value);
    }
    return search(root->left,value);
}


 node*newnode(int item){
     node*temp=(node*)malloc(sizeof(node));
     temp->data=item;
     temp->left =NULL;
     temp->right=NULL;
     return temp;
}

void inorder(node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d \n",root->data);
        inorder(root->right);
    }
}

node*insert(node*node,int val){
    if(node==NULL){
        return newnode(val);
    }
    if(val < node->data){
        node->left=insert(node->left,val);
    }
    if(val > node->data){
        node->right = insert(node->right,val);
    }
    return node;
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

     return 0;

}
