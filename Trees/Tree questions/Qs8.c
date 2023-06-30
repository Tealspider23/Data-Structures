#include <stdio.h>
#include <stdlib.h>

//Check if two trees are mirror of each other

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

int isMirror(Node*root1, Node*root2){
    if(root1==NULL && root2==NULL){
        return 1;
    }
    if(root1==NULL || root2==NULL){
        return 0;
    }
    return root1->data==root2->data && isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
}

int main() {
    Node* root1 = newNode(5);
    root1->left = newNode(1);
    root1->right = newNode(6);
    root1->right->left = newNode(3);
    root1->right->right = newNode(7);
    root1->left->left = newNode(2);
    root1->left->right = newNode(4);
    Node* root2 = newNode(5);
    root2->left = newNode(6);
    root2->right = newNode(1);
    root2->right->left = newNode(7);
    root2->right->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(2);
    if (isMirror(root1,root2)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}