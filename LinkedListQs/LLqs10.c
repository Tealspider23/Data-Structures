//Remove duplicates from a sorted Linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void RemoveDuplicates(struct node*head){
    struct node *temp ;
    struct node* p;

    if(head==NULL){
        return;
    }

    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data){
            p=temp->next->next;
            free(temp->next);
            temp->next=p;
        }
        else{
            temp=temp->next;
        }
    }  

}

void push(struct node** head, int new_data)
{
	
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node;
}

void display(struct node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

int main(){
 struct node *a =NULL;
    push(&a, 5);
	push(&a, 10);
	push(&a, 10);
	push(&a, 10);
	push(&a, 23);
	push(&a, 33);

    RemoveDuplicates(a);
    display(a);


return 0;
}