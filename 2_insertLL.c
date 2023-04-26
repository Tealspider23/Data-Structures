#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*link;
};
int calcSize(struct node *node){
    int size =0;
    while(node!=0){
        node = node->link;
        size++;
    }
    return size;
}

void insertpos(int pos , int data , struct node **head){
    int size = calcSize(*head);

    //checking if position is out of bounds
    if(pos<1 || pos>size){
        printf("No insertion");
    }else{

        // for valid positon we insert a variable temp which will
        //store the value of previous node and assign it 
        //with the value of new node

        struct node*temp=*head;
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        
        //assigning the newnode with provided data
        newnode->data = data;
        newnode->link=0;

        //now running the while loop

        while(--pos){
            temp=temp->link;
        }
        newnode->link=temp->link;
        temp->link=newnode;

    }

}



void insertStart(struct node **head, int data) //double pointer 
{

  struct node *newNode = (struct node *) malloc (sizeof (struct node));

  newNode ->data = data;
  newNode ->link = *head;

  //changing the new head to this freshly entered node
  *head = newNode;
}
void insertLast (struct node **head, int data)
{

  struct node *newNode = (struct node *) malloc (sizeof (struct node));

  newNode->data = data;
  newNode->link = 0;

  //need this if there is no node present in linked list at all
  if (*head == 0)
    {
      *head = newNode;
      return;
    }

  struct node *temp = *head;

  while (temp->link != 0)
    temp = temp->link;

  temp->link = newNode;
}

void display(struct node* node){
    while(node!=0){
        printf("%d",node->data);
        node = node->link;
        printf("\n");
    }

}

int main(){

struct node *head,*newnode ,*temp ; // creation of head pointer , newnode pointer and  temp pointer
head=0; // initialisation
int choice=1; 
// just for linked list implementation
while(choice){

newnode = (struct node*)malloc(sizeof(struct node)); //assigning storage according to struct node which 4 + 4 = 8 bytes here

printf("Enter Data :");

scanf("%d", &newnode->data); //when assigning data , here assign to the newnode

newnode->link=0; // if it is single then its next address should be 0 so initialisation

if(head==0){
    head=temp=newnode; //assigning head the first node
}else{
    temp->link=newnode;
    temp=newnode;
}
printf("Do you want to continue(0,1) ?"); // for entering new elements
scanf("%d",&choice);
}

printf("Linked list :");
temp =head;

while(temp!=0){
    printf("%d \n",temp->data);
    temp=temp->link;
}

printf("Before insertion of element :");

display(head);

printf("After insertion of element :");

insertStart (&head, 23);
insertLast(&head,56);
insertpos(2,18,&head);

display(head);

return 0;


}


