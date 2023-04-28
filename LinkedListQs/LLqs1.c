#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//Qs1 Print the middle of the linked list 

struct node{
    int data;
    struct node*next;
};

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

void print_Middle(struct node * head){
    struct node*first_ptr =head;
    struct node*second_ptr=head;

    if (head!=NULL){
        // The logic behind is to traverse the linked list with two pointers
        //one at normal speed and other twice at first
        //when the fast pointer reaches to the end , slow pointer
        //will be in the middle of the linked list.
        while(second_ptr !=NULL && second_ptr->next !=NULL){
            second_ptr=second_ptr->next->next;
            first_ptr=first_ptr->next;
        }
        printf("The middle element of the linked list : %d",first_ptr->data);
        
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

printf("Linked list :");
display(head);

print_Middle(head);

}