#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack{
    int top;
    int maxsize;
    int *array;
};

struct Stack* create(int max)
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->maxsize=max;
    stack->top=-1;
    stack->array=(int*)malloc(stack->maxsize*sizeof(int));

    // in the above statements memory is being created . Dynamically assigning malloc .
    // so if max = 5 , then array size would be 5*4 =20
}

int isFull(struct Stack *stack)
{
    if(stack->top == stack->maxsize - 1){
        printf("Maximum memory reached .");
    }
    return stack->top == stack->maxsize-1;

}

int isEmpty(struct Stack* stack){
    return stack->top == -1; 
}

void Push(struct Stack* stack,int item){

    if(isFull(stack)){
        return;
    }
    stack->array[++stack->top]=item;
    printf("%d has been successfully pushed \n",item);

}

int Pop(struct Stack* stack){
    if(isEmpty(stack)){
        return INT_MIN;
    }
    return stack->array[stack->top--];

 
}

int peek(struct Stack* stack){
    if(isEmpty(stack)){
        return INT_MIN;
    }
    return stack->array[stack->top];

}

int main(){
    int n;
    printf("How many elements you want to enter in stack ? :");
    scanf("%d",&n);
    struct Stack* stack =create(n);

    Push(stack,5);
    Push(stack,15);
    Push(stack,30);
    Push(stack,13);

    return 0;
}

  
    




