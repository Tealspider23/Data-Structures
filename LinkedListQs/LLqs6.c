#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
    struct node*prev;
};

int findsize(struct node*head){
    int count=0;
    struct node*temp;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

void push(struct node** head,int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*head;
   newnode->prev=NULL;

    if((*head)!=NULL){
        (*head)->prev =newnode;

    }
    (*head)=newnode;
}

void main(){
    struct node*head=NULL;

    push(&head,23);
    push(&head,13);
    push(&head,12);
    printf("%d\n",findsize(head));
    rev(head);
}