#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Level order traversal (Line by Line)

//Spiral traversal 
 // - Nodes are traversed in alternate order .

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
  void printgivenlevel(node*root ,int level , int itr){

    if(root==NULL){
        return;
    }
    if(level==1){
        printf("%d \n",root->data);
    }
    if(level>1){
        if(itr){
            printgivenlevel(root->left , level-1 ,itr);
            printgivenlevel(root->right,level-1 ,itr); 
            }
            else{
                printgivenlevel(root->right ,level-1,itr);
                printgivenlevel(root->left,level-1,itr);
            }
    }
 }

 void printspiral(node*root){
    int h =height(root);
    int i ;

    bool itr =false;
    for (i=0; i <=h; i++)
    {
        printgivenlevel(root,i,itr);
        itr = !itr;
    }
    
 }


/*
 void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h;i++)
        printsamelevel(root, i);
}
 void printsamelevel(node*root , int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        printf("%d \t",root->data);
    }
    else if(level>1){
        printsamelevel(root->left,level-1);
        printsamelevel(root->right,level-1);
    }
 }
 */

 int main()
{
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
 
    //printf("Level Order traversal of binary tree is \n");
     printf("Level Order traversal of binary tree is \n");
    printspiral(root);
 
    return 0;
}
 
