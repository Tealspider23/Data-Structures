#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
    struct node*prev;
};

int calcSize (struct node *node)
{
  int size = 0;

  while (node != NULL)
    {
      node = node->next;
      size++;
    }
  return size;
}

void display (struct node *node)
{
  struct node *end;
  printf ("\nIn Forward Direction\n");
  while (node != NULL)
    {
      printf (" %d ", node->data);
      end = node;
      node = node->next;
    }

  printf ("\nIn Backward direction \n");
  while (end != NULL)
    {
      printf (" %d ", end->data);
      end = end->prev;
    }
}

void delstart(struct node **head){

    struct node* temp = *head;


// If linked list has no nodes at all
    if(*head==0){
        printf("Linked list empty , nothing to delete :");
        return;
    }
    //if linked list has only 1 node 
    if(temp->next ==NULL){
        printf("Data deleted : %d",temp->data);
        *head = 0;
        return;
    }
    //mode head to next node ;
    
    (*head) =(*head)->next;
    
    //assign node's previous value as NULL

    (*head)->prev=0;
    printf("Deleted Data :%d",temp->data);
    free(temp);


}

void delend(struct node **head){
    struct node*temp =*head;

    //checking if node is empty
    if(*head==0){
        printf("Nothing to delete .");
        return;
    }
    //If list only has 1 node 
    if (temp->next==0){
        printf("Element deleted : %d",temp->data);
        *head=0;
        return;

    }
    //traverse to the last node 
    while(temp->next !=0){
        temp=temp->next;

        struct node *secondlast=temp->prev;
        secondlast->next=0;

        printf("Element deleted : %d",temp->data);
        free(temp);

    }


}

void delpos(struct node **head ,int pos ){

 struct node *temp = *head;

 int size = calcSize(*head);

 //check
 if (pos<1 || pos>size){
    printf("Invalid !");
    return;
 }
 //only 1 node
 if (pos==1){
    delstart(*head);
    return;
 }
 if (pos==size){
    delend(*head);
    return;
 }
 while(--pos){
    temp =temp->next;
 }
 struct node* prevnode=temp->prev;
 struct node* nextnode =temp->next;

 //assigning prevnode to next node
 prevnode->next=nextnode;

 //assigning nextnode to prev node 
 nextnode->prev = temp->prev;

 printf("Element deleted : %d",temp->data);
 free(temp);
}





void main(){


struct node *head,*newnode ,*temp ; // creation of head pointer , newnode pointer and  temp pointer
head=0; // initialisation
int choice=1; 
// just for linked list implementation
while(choice){

newnode = (struct node*)malloc(sizeof(struct node)); //assigning storage according to struct node which 4 + 4 = 8 bytes here

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

printf("After deleting the initial element ");
delstart(&head);
display(head);

}