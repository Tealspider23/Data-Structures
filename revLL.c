#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

void reverseLL(struct node **head){
    struct node *prev = 0;
    struct node *next = 0;
    struct node *curr = *head;

    while(curr!=0){

        //Store next 
        next = curr->next;

        //Reverse current node's pointer
        curr->next=prev;

        // Now Move pointers one position ahead 
        prev=curr;
        curr=next;
    }
    *head = prev;
}

void display(struct node* node){
    while(node!=0){
        printf("%d",node->data);
        node = node->next;
        printf("\n");
    }

}


void main(){


struct node *head,*newnode ,*temp ; // creation of head pointer , newnode pointer and  temp pointer
head=0; // initialisation
int choice=1; 
// just for linked list implementation
int t=0;
int data;
while(choice){

newnode = (struct node*)malloc(sizeof(struct node)); //assigning storage according to struct node which 4 + 4 = 8 bytes here

printf("Enter Data:");

scanf("%d", &newnode->data); //when assigning data , here assign to the newnode

newnode->next=0; // if it is single then its next address should be 0 so initialisation

if(head==0){
    head=temp=newnode; //assigning head the first node
}else{
    temp->next=newnode;
    temp=newnode;
}
printf("Do you want to continue(0,1) ?"); // for entering new elements
scanf("%d",&choice);
}

printf("Original Linked List :");

display(head);

printf("Reverse linked list :");

reverseLL(&head);
display(head);

}



