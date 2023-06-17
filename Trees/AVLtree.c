#include <stdio.h>
#include <stdlib.h>

// AVL TREES - 
// AVL is a self balancing Binary Search Tree . THis is implemented by using a balancing factor
// THe balancing factor implies - Total height of left sub tree - Total height of right sub tree 
// AVL has 4 primary rotations -
//  1] LL 
//  2] RR 
//  3] LR 
//  4] RL 
//  Suppose a BST like this - 

//      20
//       \
//        30
//           \
//            35

// Here 35 has 0 balance factor  
// 30 has 1 balance  factor  
// 20 has 2 


// Here 20 is the one in fault as the balancing factor must be { -1 , 0 , 1}
// To balance this  the ideal approach is - 

//         30
//        /  \
//       20   35

// More Details in Copy - 


 typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
    int height;
}Node;

int height(Node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

int max(int a , int b){
    if(a>b){
        return a ;
    }
    return b;
}


Node* newnode(int value){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}     

Node* rightrotate(Node*x){
    Node*w = x->left;
    Node*y= w->right;

    w->right = x;
    x->left = y;


    x->height = max(height(x->left) ,height(x->right)) + 1;
    w->height = max(height(w->left), height(w->right)) +1 ;

    return w;
}

Node* leftrotate(Node*x){
    Node*y = x->right;
    Node*w = y->left;

    y->left = x;
    x->right = w;

    x->height = max(height(x->left), height(x->right)) +1;
    y->height = max(height(y->left) , height(y->right)) +1;

    return y;

}

int getbalance(Node*n){
    if(n==NULL){
        return 0;
    }
    return height(n->left) - height(n->right);
}

Node*insert(Node* node , int value){

    if(node==NULL){
        return(newnode(value));
    }
    if(value < node->data){
        node->left = insert(node->left ,  value);
    }
    else if(value > node->data){
        node->right = insert(node->right , value);
    }
   else{ //DUPLICATE VALUES ARE NOT ALLOWED IN AVL BSTS
    return node;
   }

 node->height = 1 + max(height(node->left) , height(node->right));

 int balance = getbalance(node);

//LEFT LEFT CASE 
 if(balance > 1 && value < node->left->data){
    return rightrotate(node);
 }
 //RIGHT RIGHT CASE
 if(balance < -1 && value > node->right->data){
    return leftrotate(node);
 }
 //LEFT RIGHT CASE
 if(balance > 1  && value >  node->left->data){
    node->left = leftrotate(node->left);
    return rightrotate(node);
 }
 //RIGHT LEFT CASE
 if(balance < -1 && value < node->right->data){
    node->right = rightrotate(node->right);
    return leftrotate(node);
 }

 return node;

}

void inorder(Node*t){

    if(t!=NULL){
 
    inorder(t->left);
       printf("%d \n ", t->data);
    inorder(t->right);
}
}

int main(){

    Node* root = NULL;

    root = insert(root , 6);
     root = insert(root , 7);
      root = insert(root , 8);
       root = insert(root , 9);
        root = insert(root , 13);
         root = insert(root , 11);
          root = insert(root , 12);
           root = insert(root , 10);


           inorder(root);




}



     

