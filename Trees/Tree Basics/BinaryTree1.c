#include <stdio.h>
#include <stdlib.h>

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

void inorder(node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d \n",root->data);
        inorder(root->right);
    }
}

void preorder(node*root){
    if(root!=NULL){
        printf("%d \n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d \n",root->data);
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

 int main(){

    node*root = NULL;
    int data;
    root = insert(root ,9);
    int choice =1;
    while(choice){
        printf("Enter data in the node :");
        scanf("%d",&data);
        insert(root , data);
        printf("Do you want to enter further nodes (0,1):");
        scanf("%d",&choice);
    }
    printf("The postorder is \n");
    postorder(root);

    printf("The inorder is \n");
    inorder(root);

    printf("The preorder is \n");
    preorder(root);

    return 0;
 }
    
    

    
