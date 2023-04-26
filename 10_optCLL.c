#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};


void display(struct node* head){

if(head==0){
    return;
}
struct node*temp=head;
do{
    printf("%d \n",temp->data);
    temp=temp->next;
}
while(temp!=head);
    printf("\n");

}


void insertstart(struct node **head , int data){
    struct node *newnode = (struct node *) malloc (sizeof (struct node));
  newnode->data = data;

  // if its the first node being entered
  if (*head == NULL)
    {
      *head = newnode;
      (*head)->next = *head;
      return;
    }

  // if LL already as >=1 node
  struct node *curr = *head;

  // traverse till last node in LL
  while (curr->next != *head)
    {
      curr = curr->next;
    }
  // assign LL's last node's next as this new node
  curr->next = newnode;

  // assign newNode's next as current head
  newnode->next = *head;

  // change head to this new node
  *head = newnode;
}


void insertlast(struct node **head , int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if(*head==0){
        *head = newnode;
        (*head)->next =*head;
        return;
    
    }
    //  If LL has already one node
    struct node* temp = *head;

    //traverse till last node;
      while (temp->next != *head)
    {
      temp = temp->next;
    }
  // assign LL's last node's next as this new node
  temp->next = newnode;

  // assign newNode's next as current head
  newnode->next = *head;

}
//Note - The only code fragment omitted in the insertlast is the last statement
//We are not changing *head = newnode , as we are inserting at last .


void insertpos(struct node **head , int pos , int data){

struct node *newnode , *currnode ;
int i;

if(*head == 0){
    printf("List is empty!");
}
if (pos==1){
    insertstart(head,data);
    return;
}
else{
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    currnode=*head;
    while(--pos>1){
      currnode=currnode->next;
    }
    newnode->next=currnode->next;
    currnode->next=newnode;
    // assigning the current node the value of newnode 
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
temp->next=head;
printf("Do you want to continue(0,1) ?"); // for entering new elements
scanf("%d",&choice);
}

display(head);
printf("After inserting element at beginning :23");
insertstart(&head,23);
printf("After inserting element 47 at last ");
insertlast(&head,47);
printf("And lastly inserting 66 at the 3rd index");
insertpos(&head,3,66);
display(head);

}
