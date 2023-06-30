#include <stdio.h>
#include <stdlib.h>

//Construct Complete Binary Tree from its Linked List Representation

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

Node* newNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

TreeNode* newTreeNode(int value) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void push(Node** head, int value){
    Node* temp = newNode(value);
    temp->next = *head;
    *head = temp;
}

void printLL(Node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void printTree(TreeNode* root){
    if(root==NULL){
        return;
    }
    printTree(root->left);
    printf("%d ",root->data);
    printTree(root->right);
}

TreeNode* construct(Node*head){
    if(head==NULL){
        return NULL;
    }
    TreeNode*root = newTreeNode(head->data);
    Node*temp = head;
    Node*prev = NULL;
    while(temp!=NULL){
        if(temp->data==root->data){
            prev->next=NULL;
            break;

        }
        prev = temp;
        temp = temp->next;
    }
    root->left = construct(head);
    root->right = construct(temp->next);
    return root;

}

int main() {
    Node* head = NULL;
    push(&head, 36);
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10);
    printLL(head);
    TreeNode* root = construct(head);
    printTree(root);
    return 0;
}
