#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
    struct node*prev;
};

//Insertion in Doubly linked list
void insertStart (struct node **head, int data)
{

  // creating memory for newNode
  struct node *newNode = (struct node *) malloc (sizeof (struct node));

  // assigning newNode's next as the current head 
  // Assign data & and make newNode's prev as NULL
  newNode->data = data;
  newNode->next = *head;
  newNode->prev = NULL;

  // if list already had item(s)
  // We need to make current head previous node as this new node
  if (*head != NULL)
    (*head)->prev = newNode;

  // change head to this newNode
  *head = newNode;

}
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

void insertpos(struct node **head,int pos , int data){
    int size = calcSize(*head);

    if (pos<1 || pos>size){
        printf("Can't insert at the given positon .");
    }else{
        struct node *temp=*head;
        struct node *newnode =(struct node*)malloc(sizeof(struct node));
        newnode->data =data;
        newnode->next=0;

        while(--pos){
            temp=temp->next;
        }
        newnode->next =temp->next;
        newnode->prev=temp;
        temp->next=newnode;
    }

}
void insertlast(struct node **head,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = 0;

   // If no head present in the list at all
   if(*head==0){
    *head =newnode;
    newnode->prev=0;
    return;
   }
   struct node*temp;
   while(temp->next!=0){
    temp=temp->next;
    temp->next = newnode;
    newnode->prev =temp;

   }
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
//printf("Doubly Linked list : ");
//display(head);

insertStart(&head,34);
printf("After inserting 34 at first : \n");
display(head);
printf("After inserting 12 at 3rd index : \n");
insertpos(&head,3,12);
display(head);
printf("After inserting 99 at last index : \n");
insertlast(&head,99);
display(head);

}

