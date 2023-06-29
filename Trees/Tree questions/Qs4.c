#include <stdio.h>
#include <stdlib.h>

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

int isSibling(Node* root, Node* x, Node* y) {
    if (root == NULL) {
        return 0;
    }
    return ((root->left == x && root->right == y) || (root->left == y && root->right == x) ||
            isSibling(root->left, x, y) || isSibling(root->right, x, y));
}

int getLevel(Node* root, Node* node, int level) {
    if (root == NULL) {
        return 0;
    }
    if (root == node) {
        return level;
    }
    int leftLevel = getLevel(root->left, node, level + 1);
    if (leftLevel != 0) {
        return leftLevel;
    }
    return getLevel(root->right, node, level + 1);
}

int isCousin(Node* root, Node* x, Node* y) {
    return (getLevel(root, x, 1) == getLevel(root, y, 1)) && !isSibling(root, x, y);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->right = newNode(4);
    root->left->left = newNode(5);
    root->left->right = newNode(6);
    Node* x = root->left->left;
    Node* y = root->right->right;
    if (isCousin(root, x, y)) {
        printf("Nodes are cousins.\n");
    } else {
        printf("Nodes are not cousins.\n");
    }
    return 0;
}
