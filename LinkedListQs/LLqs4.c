#include <stdio.h>
#include <stdlib.h>

//Count nodes in a Circular Linked list 

struct Treenode{
    int data;
    struct Treenode*next;
};

void display (struct Treenode *node)
{

  //as linked list will end when Node is Null
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
  printf ("\n");
}

int countnodes(struct Treenode *head ){

 struct Treenode *temp = head;
 int count = 0;
 if(head!=NULL){
 do{
    temp=temp->next;
    count++;
 }while(temp != head);
 }
 return count;
}


void main(){
    
struct Treenode *head,*newnode ,*temp ; // creation of head pointer , newnode pointer and  temp pointer
head=0; // initialisation
int choice=1; 
// just for linked list implementation
int t=0;
int data;
while(choice){

newnode = (struct Treenode*)malloc(sizeof(struct Treenode)); //assigning storage according to struct node which 4 + 4 = 8 bytes here

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
//printf("The no. of nodes present in the linked list :%d",countnodes(head));

}