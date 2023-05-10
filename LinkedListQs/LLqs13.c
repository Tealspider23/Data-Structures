#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// to Merge two sorted Linked lists 
typedef struct node{
    int data;
    struct node*next;
}node;

void movenode(node** destref,node** sourceref);

    /* Taking two lists in sorted increasing order and splices their node
    node together and make one big sorted list which is returned */

node* sortedMerge(node*a,node*b){
    node* result = NULL;

    //Base case
    if(a==NULL){
        return (b);
    }
    if(b==NULL){
        return (a);
    }

    //Time for recursion
    if(a->data <= b->data){
        result =a;
        result->next=sortedMerge(a->next,b);
    }
    else{
        result =b;
        result->next = sortedMerge(a,b->next);
    }
    return (result);
}

    void Movenode(node**destref,node**sourceref){
        node* newnode= *sourceref;
        assert(newnode!=NULL);

        *sourceref=newnode->next;
        newnode->next=*destref;
        *destref=newnode;
    }


void push(node**head,int data){
    node* newnode =(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=(*head);
    (*head)=newnode;
}


void display(node* node){
    while(node!=NULL){
        printf("%d \n",node->data);
        node=node->next;
    }

}


int main(){
     node* res = NULL;
     node* a = NULL;
     node* b = NULL;

      push(&a, 15);
    push(&a, 10);
    push(&a, 5);
 
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
 
    /* Remove duplicates from linked list */
    res = sortedMerge(a, b);
 
    printf("Merged Linked List is: \n");
    display(res);
 
    return 0;

}