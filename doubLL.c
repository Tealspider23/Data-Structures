#include<stdio.h>
#include<stdlib.h>

// Structure of doubly linked list 
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

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
while(choice){

newnode = (struct node*)malloc(sizeof(struct node)); //assigning storage according to struct node which 4 + 4 + 4 =12 bytes here

printf("Enter Data:");

scanf("%d", &newnode->data); //when assigning data , here assign to the newnode

newnode->next= 0;
newnode->prev =0; // if it is single then its next address should be 0 so initialisation

if(head==0){
    head=temp=newnode; //assigning head the first node
}else{
    temp->next=newnode;
    newnode->prev=temp;
    temp=newnode;
}
printf("Do you want to continue(0,1) ?"); // for entering new elements
scanf("%d",&choice);
}
printf("Doubly Linked list : ");
display(head);

}


