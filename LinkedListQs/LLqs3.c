#include <stdio.h>
#include <stdlib.h>

//Write a function that counts the no of times a given int occurs in a linked list

struct node{
    int data;
    struct node*next;
};



int countsearch(struct node *head , int element){

 struct node *temp = head;

int count =0;
while(temp!=NULL){
    if(temp->data == element){
        count++;
    }
        temp=temp->next;
    
}
    return count;

}

void display (struct node *node)
{

  //as linked list will end when Node is Null
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
  printf ("\n");
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

printf("Linked list :");
display(head);

printf("Now lets see how many times 23 is repeated :");
int count=countsearch(head,23);
printf("%d",count);

}