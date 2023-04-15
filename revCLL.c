#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}

void reverseCLL(struct node **head){

    struct node *prev , *cur , *next,*last ;//temporary pointers that will help

    if (*head == 0){
        printf("Linked list is empty . can't reverse .");
    }

    // last will be the head node .
    last = *head;
    prev =*head;
    cur = (*head)->next;
    *head = (*head)->next;

    while(*head!=last){
        *head = (*head)->next;
        cur->next=prev;
        prev =cur;
        cur =*head;

    }

    cur->next =prev;
    *head =prev; //making last node as head


}