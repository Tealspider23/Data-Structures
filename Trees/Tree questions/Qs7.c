#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Check if a Binary Tree contains duplicate subtrees of size 2 or more

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

char* dupSubUtil(Node* root, int*m){
   if(root==NULL){
    return "$";
   }
   char* s = (char*)malloc(sizeof(char)*100);
    sprintf(s,"%d%s%d",root->data,dupSubUtil(root->left,m),dupSubUtil(root->right,m));
    if(strlen(s)>3 && s[0]==s[2] && s[1]==s[3]){
        *m=1;
    }

    return s;
}

int dupSub(Node*root){
    int m = 0;
    dupSubUtil(root,&m);
    return m;
}

int main() {
    Node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    if (dupSub(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}





 

  



