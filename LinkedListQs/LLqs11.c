//Intersection of two sorted Linekd lists

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*next;
};

void display(struct node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}
void push(struct node** head, int new_data)
{
	
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node;
}

struct node* Intersection (struct node*a, struct node*b){
if(a==NULL || b==NULL){
    return NULL;
}
//check for greater , smaller and equal to
if(a->data > b->data){
    return Intersection(a,b->next);
}
if(a->data < b->data){
    return Intersection(a->next,b);
}

struct node* newnode = (struct node*)malloc(sizeof(struct node));
newnode->data=a->data;
newnode->next = Intersection(a->next,b->next);

return newnode;

}

int main()
{
    /* Start with the empty lists */
    struct node* a = NULL;
    struct node* b = NULL;
    struct node* intersect = NULL;
 
    
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);
 
    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);
 
   
    intersect = Intersection(a, b);
 
    printf("\n Linked list containing common items of a & b \n ");
    display(intersect);
 
    return 0;
}


