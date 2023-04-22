#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// using linked list , implementation of Stack


struct node{
    int data;
    struct node *next;
};
struct node*top= NULL;

void Push(int item){
    struct node* new_node =(struct node*)malloc(sizeof(struct node));
    new_node->data =item;
    new_node->next =top;
    top=new_node;
}

int pop(){
    if(top==NULL){
        printf("Stack is Empty !");
        return -1;
    }
    //Switching the values of top with next node  and freeing it .
    int item = top->data;
    struct node*temp=top;
    top = top->next;
    free(temp);
    return item;
}

void display(){
    struct node * temp = top;
    
    while(temp!=NULL){
        printf("%d \n",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}


int main()
{
    Push(10);
    Push(20);
    Push(30);
    printf("Linked List\n");
    display();
    pop();
    printf("After the pop, the new linked list\n");
    display();
    pop();
    printf("After the pop, the new linked list\n");
    display();

    return 0;
}




