#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

//using Recursion to reverse a Queue - use reverse function and dont use stack

//using Stack to dequeue and push and then pop and enqueue 

struct Queue{
    int items[MAXSIZE];
    int front;
    int rear;
};

struct Stack{
    int items[MAXSIZE];
    int top;
};

void push(struct Stack*s,int item){
    if(s->top==MAXSIZE-1){
        printf("Overflow");
        return;
    }
    s->top++;
    s->items[s->top]=item;

}

int pop(struct Stack*s){
    if(s->top==-1){
        printf("Stack Empty");
        return -1;
    }
    int item=s->items[s->top];
    s->top--;

    return item;
}

void enqueue(struct Queue*q,int item){
    if(q->rear==MAXSIZE-1){
        printf("overflow");
        return;
    }
    if(q->front==-1){
        q->front=0;
    }
    q->rear++;
    q->items[q->rear]=item;

    }

int dequeue(struct Queue *q){
    if(q->front==-1){
        printf("Underflow");
        return -1 ;
    }
    int item =q->items[q->front];
    q->front++;

    if(q->front > q->rear){
        q->front= -1;
        q->rear = -1;

    }
    return item;
}

void display(struct Queue *q){
    if(q->rear==-1){
        printf("Empty queue");
    }
    for (int i = q->front ; i <= q->rear; i++)
    {
        printf("%d \n",q->items[i]);
    }
    printf("\n");

}

void reverse(struct Queue *q){
    if(q->front==-1){
        return;
    }
    int item =dequeue(q);
    reverse(q);
    enqueue(q,item);
}
    
int main(){
    struct Queue q;
    q.front=-1;
    q.rear=-1;

    struct Stack s;
    s.top=-1;

    enqueue(&q,23);
    enqueue(&q,32);
    enqueue(&q,12);
    enqueue(&q,43);
    enqueue(&q,99);

    printf("before reversing :");
    display(&q);
    //reverse(&q);

    while(q.front!=-1){
        push(&s,dequeue(&q));
    }
    while(s.top!=-1){
        enqueue(&q,pop(&s));
    }

    printf("After reversing : ");
    display(&q);

    return 0;

}
    






