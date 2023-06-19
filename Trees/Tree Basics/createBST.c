#include <stdio.h>
#include <stdlib.h>

//insertion in BST is done by comparing the node elements and then taking respective action.
// Like the element smaller than the given node is compared with the left of the node and 
// the element greater than the given node is compared with the right of the node . Accordingly insertion
// is done

//deletion has three cases
// for nodes containing two sub nodes , there are two methods
// using inorder predecessor
// -replacing the node with the largest value from left sub node

// using inorder successor
//replacing the node with the smallest element from the right node


struct Treenode 
{ 
    int val; 
    struct Treenode *left, *right; 
}; 
   
struct Treenode* newNode(int item) 
{ 
    struct Treenode* temp =  (struct Treenode *)malloc(sizeof(struct Treenode)); 
    temp->val = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
void inorder(struct Treenode* root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->val); 
        inorder(root->right); 
    } 
} 
   
struct Treenode* insert(struct Treenode* node, int val) 
{ 
    if (node == NULL) return newNode(val); 
  
    if (val < node->val) 
        node->left  = insert(node->left, val); 
    else if (val > node->val) 
        node->right = insert(node->right, val);    
  

    return node; 
} 
   
int main() 
{ 
    
    struct Treenode* root = NULL; 
    root = insert(root, 100); 
    insert(root, 60); 
    insert(root, 40); 
    insert(root, 80); 
    insert(root, 140); 
    insert(root, 120); 
    insert(root, 160);
    
   
    
    inorder(root); 
   
    return 0; 
} 
