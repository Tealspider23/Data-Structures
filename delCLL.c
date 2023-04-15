#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;

};
void delbeg(struct node **head){
    
     struct node *temp = *head;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }

  // if only 1 node in CLL
  if (temp->next == *head)
    {
      *head = NULL;
      return;
    }

  struct node *curr = *head;

  // traverse till last node in CLL
  while (curr->next != *head)
    curr = curr->next;

  // assign last node's next to 2nd node in CLL
  curr->next = (*head)->next;

  // move head to next node
  *head = (*head)->next;
  free (temp);
}


void delend(struct node **head){
    
    struct node *temp=*head;
    struct node *prevnode;


    if (*head == 0){
        printf("nothing to delete");
        return;
    }
    if (temp->next == *head){
        *head=0;
        return;
    }

    while(temp->next != *head){
        //storing the previous node value so that we can access this value
        prevnode=temp;
        //now going to the end 
        temp=temp->next;
    }
    prevnode->next =*head;
    free(temp);
    //the prev node now becomes the last node . it was the second last node .

}

void delpos(struct node **head , int pos ){
 
 int size = calcsize(*head);
    //checking if empty
  ifs (pos<1 || pos>size){
    printf("Invalid index");
  }
  else if (pos==1){
    delbeg(head);
  }
  else if(pos==size){
    delend(head);
  }
  else{
    struct node *temp = *head;
    struct node *prev ;

    while(--pos){
        //storing previous link
        prev = temp;
        temp=temp->next;
    }
   // now change the previous node's next node to pos 's next node
   prev->next = temp->next;
   //delete the pos node
   free(temp);
  }

  }
    



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

int calcsize(struct node *head){
    int size =0;
    struct node *temp = head;

    if (temp==0){
        return size;
    }
    do
    {
        size++;
        temp=temp->next;
        /* code */
    } while (temp!=head);
    return size;
    
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

printf("Linked list after deletion :");
delend(&head);
display(head);

}