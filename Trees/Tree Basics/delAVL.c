#include <stdio.h>
#include <stdlib.h>

// Program for Deletion in a AVL Tree Data Structure

typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
    int height;
}Node;

int max(int a , int b){
    if(a>b){
        return a ;
    }
    return b;
}

int height(Node*n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

Node* newnode(int data){
    Node*newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}


Node* rightrotate(Node*x){
    Node*w = x->left;
    Node*y = w->right;

    w->right = x;
    x->left = y;

    x->height = max(height(x->left), height(x->right)) +1;
    w->height = max(height(w->left), height(w->right)) +1;

    return w;

}

Node* leftrotate(Node*x){
    Node*y = x->right;
    Node*w = y->left;

    y->left = x;
    x->right = w;

    x->height = max(height(x->left), height(x->right)) +1;
    y->height = max(height(y->left), height(y->right)) +1;

    return y;
}

int getbalance(Node*n){
    if(n==NULL){
        return 0;
    }
    return height(n->left) - height(n->right);
}

Node*insert(Node*node,int data){
    if(node==NULL){
        return newnode(data);
    }
    if(data < node->data){
        node->left = insert(node->left,data);
    }
    if(data > node->data){
        node->right = insert(node->right,data);
    }
    else{
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getbalance(node);

    if(balance > 1 && data < node->left->data){
        return rightrotate(node);
    }
    if(balance < -1 && data > node->right->data){
        return leftrotate(node);
    }
    if(balance > 1 && data > node->left->data){
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    if(balance < -1 && data < node->right->data){
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}

Node *minvaluenode(Node*nt){
  Node* current = nt;

  while(current->left != NULL){
    current = current->left;
  }
  return current;
}

Node* deletenode(Node*root , int val){
    if(root==NULL){
        return root;
    }

    if(val<root->data){
        root->left = deletenode(root->left , val);
    }
    else if(val>root->data){
        root->right = deletenode(root->right , val);
    }
    else{
        if(root->left == NULL || root->right == NULL){
            Node*temp = root->left ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp;
            }
            free(temp);
        }
        else{
            Node*temp = minvaluenode(root->right);

            root->data = temp->data;

            root->right = deletenode(root->right , temp->data);
        }
    }
    if(root==NULL){
        return root;
    }

    root->height = 1+ max(height(root->left), height(root->right));

    int balance = getbalance(root);

    if(balance > 1 && getbalance(root->left) >= 0){
        return rightrotate(root);
    }
    if(balance < -1 && getbalance(root->right) <= 0){
        return leftrotate(root);
    }
    if(balance>1 && getbalance(root->left) < 0){
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance<-1 && getbalance(root->right) > 0){
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

void preorder(Node*root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


int main(){
    Node*root = NULL;
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,25);

    preorder(root);
    printf("\n");

    root = deletenode(root,30);

    preorder(root);
    printf("\n");

    return 0;
}