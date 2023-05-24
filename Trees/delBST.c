#include <stdio.h>
#include <stdlib.h>

//Deletion of nodes from a Binary Search Tree 
typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;

void inorder(node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d \n",root->data);
        inorder(root->right);
    }
}


 node*newnode(int item){
     node*temp=(node*)malloc(sizeof(node));
     temp->data=item;
     temp->left =NULL;
     temp->right=NULL;
     return temp;
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
// Now Deletion has 3 Cases 
/*   1)the node to be deleted has no child nodes
     2)the node to be deleted has only one child
     3)the node to be deleted has 2 child nodes .*/


     node* deletenode(node*root,int key){
        if(root==NULL){
            return root;
        }
        if(key<root->data){
            root->left=deletenode(root->left,key);
        }
        else if(key > root->data){
            root->right =deletenode(root->right,key);
        }
        else{
            if(root->left==NULL){
                node*temp=root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL){
                node*temp=root->left;
                free(root);
                return temp;
            }
            node*temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
            
        }
        return root;
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
    printf("\n");
     int key = 50;
     root=deletenode(root,key);
     printf("The inorder traversal after deletion is ");
     inorder(root);


     return 0;
     }