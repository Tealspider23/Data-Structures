#include <stdio.h>
#include <stdlib.h>

/* Representation of Binary tree can be done in two methods-
  1)Sequential representation (Arrays)
  2)Dynamic Node representation (Linked Lists)
*/
typedef struct tree_node{
    struct tree_node*left;
    int data;
    struct tree_node*right;
}tree_node;

tree_node* newnode(int data){
    tree_node* node = (tree_node*)malloc(sizeof(tree_node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    return(node);
}

int main(){
  tree_node* root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(3);
  
  return 0;
}