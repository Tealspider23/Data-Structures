#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int d)
{
	struct node* new_n;
	new_n = (struct node*)malloc(sizeof(struct node));
	new_n->data = d;
	new_n->next = NULL;
	if((front == NULL)&&(rear == NULL)){
		front = rear = new_n;
	}
	else{
		rear->next = new_n;
		rear = new_n;
	}
	
}

void display()
{
	struct node* temp;
	if((front == NULL)&&(rear == NULL)){
		printf("\nQueue is Empty");
	}
	else{
		temp = front;
		while(temp){
			printf(" %d ",temp->data);
			temp = temp->next;
		}
	}
}

void dequeue()
{
	struct node *temp;
	temp = front;
	if((front == NULL)&&(rear == NULL)){
		printf("\nQueue is Empty");
	}
	else{
		front = front->next;
		free(temp);
	}
}
int main()
{
  enqueue(5);
  enqueue(10);
  enqueue(15);
  enqueue(20);
  enqueue(25);
  printf("Queue:");
  display();
  printf("\nQueue After Dequeue:");
  dequeue();
  display();
  
}
