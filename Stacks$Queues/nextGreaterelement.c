#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 30

typedef struct Stack{
    int top;
    int items[MAXSIZE];
}Stack;

void push(Stack*s,int val){

    if(s->top == MAXSIZE-1){
        printf("Overflow");
    }
    if (s->top==-1){
       s->items[++s->top]=val;

    }
}

    int Pop(Stack*s){
    if(isEmpty(s)){
        return INT_MIN;
    }
    return s->items[s->top--];
    }

 
