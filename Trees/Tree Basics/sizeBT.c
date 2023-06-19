#include <stdio.h>
#include <stdlib.h>

//Size , maximum and height of a Binary Tree

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

 int size(node*root){
    if(root==NULL){
        return 0;
    }else{
    return size(root->left)+1+size(root->right);
 }
 }

 int max(node*root){
    if(root==NULL){
        return INT_MIN;
 }
int res= root->data;
int lres=max(root->left);
int Rres=max(root->right);
if(lres>res){
    res=lres;
}else(Rres>res){
    res=Rres;
}
return res;
 }
 

  int height(node*node){

    if(node==NULL){
        return 0;
    }
    else{
        int lefth = height(node->left);
        int righth = height(node->right);

        if (lefth>righth){
            return lefth+1;
        }
        else return righth+1;
    }

 }

 int maximum(struct node*root){}



  int main()
{
     node*root = NULL;
    int data;
    root = insert(root ,1);
    int choice =1;
    while(choice){
        printf("Enter data in the node :");
        scanf("%d",&data);
        insert(root , data);
        printf("Do you want to enter further nodes (0,1):");
        scanf("%d",&choice);
    }
printf("The size of the tree is %d \n",size(root));
return 0;

}
