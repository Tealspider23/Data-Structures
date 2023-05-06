#include <stdio.h>
#include <stdlib.h>

//Exchange first and last nodes in a linked list 


// This can be done by using a extra node. The extra node is traversed .
// Either the head of the node can be exhanged with the last node and
//simultaneously the last node is assigned the 2nd node .Same as in deletion
//of 1st or last elements in a circular linked list 


struct node{
    int data;
    struct node*next;
};

struct node *Changenodes(struct node*head){

// If there are only two nodes in the linked list .
    if(head->next->next==head){
        head = head->next;
        return head;
    }
    struct node*temp = head;

    while(temp->next !=head){
        temp=temp->next;
    }
        temp->next->next = head->next;
        head->next =p->next;

    }

