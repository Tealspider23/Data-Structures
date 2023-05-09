#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int f;
    int r;
    int*arr;
};

int isFull(struct Queue *q){
  return(q->size==q-)
}


void enqueue(struct Queue*q,int element){

    if(isFull(q)){
        printf("Overflow");
    }else{
        q->r=q->r+1;
        q->arr[q->r]=element;
    }
}



