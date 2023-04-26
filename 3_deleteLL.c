#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
int calcSize(struct node *node){
    int size =0;
    while(node!=0){
        node = node->next;
        size++;
    }
    return size;
}


void display(struct node* node){
    while(node!=0){
        printf("%d",node->data);
        node = node->next;
        printf("\n");
    }
}

void delstart(struct node **head){
    struct node *temp;
    temp=*head;
    *head = temp->next;
    free(temp);

}

void delpos(struct node **head , int pos){
    struct node* temp = *head;
    struct node*previous;

    int size = calcSize(*head);

    if (pos<1 || pos>size){

        printf("Deletion not possible");
    }
    if (pos==1){
       *head = temp->next;	//changing head to next in the list

      printf ("Value %d, deleted \n", temp->data);

      //case 1: 22 deleted and freed
      free (temp);
      return;
    }
        while(--pos){

            previous = temp;

            temp = temp->next;
        }
        previous->next = temp->next;

        printf("Value deleted : %d",temp->data);
        free(temp);
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
/*
printf("Before deletion  of  start element :");

display(head);

printf("After deletion of start element :");
delstart(&head);

display(head);
*/

printf("Before deletion  of  positioned element :");

display(head);

printf("After deletion  of  positioned element :");
delpos(&head,2);
display(head);

}

