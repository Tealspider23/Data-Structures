#include <stdio.h>
#include <stdlib.h>
#define n 30

// code for implementing Queue using Stacks

int s[n],top=-1;

int pop(){
    return s[top--];
}

void push(int x){
    if(top==n-1){
        printf("Overflow");
    }else{
        top++;
        s[top]=x;
    }

}

void enqueue(int x){
    push(x);
}

int dequeue(){
    int data,res;
    if(top==-1){
        printf("Queue empty");
    }
        else if(top==0){
            return pop();
        }

        data =pop();
        res=dequeue();
        push(data);
        return res;

    
}

void display(){
    int i;
    for(i=0;i<=top;i++){
        printf("%d \n",s[i]);
    }
}

int main(){
    enqueue(5);
    enqueue(25);
    enqueue(35);
    enqueue(345);
    enqueue(455);
    printf("Queue \n");
    display();

    printf("Queue after dequeue \n");
    dequeue();
    display();
    
}