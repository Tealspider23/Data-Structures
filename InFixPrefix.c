// Method -
//1) Reverse the infix string .Interchange left and right parentheses
//2)Obtain the postfix expression of the infix expression
//3)Reverse the postfix to get prefix .


// This uses struct based stack implimentation of Stack
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>


struct Stack
{
  int top;
  int maxSize;
  int *array;
};

struct Stack *create (int max)
{
  struct Stack *stack = (struct Stack *) malloc (sizeof (struct Stack));
  stack->maxSize = max;
  stack->top = -1;
  stack->array = (int *) malloc (stack->maxSize * sizeof (int));
  return stack;
}



//Stack is full when top is equal to the last index 
int isFull (struct Stack *stack)
{
  if (stack->top == stack->maxSize - 1)
    {
      printf ("Will not be able to push maxSize reached \n");
    }
  // Since array starts from 0, and maxSize starts from 1
  return stack->top == stack->maxSize - 1;
}


// Will return true if top is -1 . 
int isEmpty (struct Stack *stack)
{
  return stack->top == -1;
}

// Push function here, inserts value in stack and increments stack top by 1
void push (struct Stack *stack, int item)
{
  if (isFull (stack))
    return;
  stack->array[++stack->top] = item;
}

// Function to remove an item from stack.  It decreases top by 1 
int pop (struct Stack *stack)
{
  if (isEmpty (stack))
    return INT_MIN;
  return stack->array[stack->top--];
}

// Function to return the top from stack without removing it 
int peek (struct Stack *stack)
{
  if (isEmpty (stack))
    return INT_MIN;
  return stack->array[stack->top];
}

// A utility function to check if the given character is operand .
int checkIfOperand (char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to compare precedence
// If we return larger value means higher precedence 
int precedence (char ch)
{
  switch (ch)
    {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;

    case '^':
      return 3;
    }
  return -1;
}


int covertInfixToPostfix (char *expression)
{
  int i, j;

  // Stack size should be equal to expression size   
  struct Stack *stack = create (strlen (expression));
  if (!stack)			// just checking is stack was created or not  
    return -1;

  for (i = 0, j = -1; expression[i]; ++i)
    {
      // Here we are checking is the character we scanned is operand or not
      // and this adding to to output. 
      if (checkIfOperand (expression[i]))
	expression[++j] = expression[i];

      else if (expression[i] == '(')
	push (stack, expression[i]);

      else if (expression[i] == ')')
	{
	  while (!isEmpty (stack) && peek (stack) != '(')
	    expression[++j] = pop (stack);
	  if (!isEmpty (stack) && peek (stack) != '(')
	    return -1;		// invalid expression              
	  else
	    pop (stack);
	}
      else			// if an opertor
	{
	  while (!isEmpty (stack)
		 && precedence (expression[i]) <= precedence (peek (stack)))
	    expression[++j] = pop (stack);
	  push (stack, expression[i]);
	}

    }

  // Once all inital expression characters are traversed
  // add all elements from stack to exp
  while (!isEmpty (stack))
    expression[++j] = pop (stack);

  expression[++j] = '\0';
  printf ("%s", expression);
}


void reverse(char *exp){

    int size =strlen(exp);
    int j=size , i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!=0){
        temp[j]=exp[i];
        j--;
        i++;

    }
    strcpy(exp,temp);
    
}

void brackets(char *exp){

    int i= 0;
    while(exp[i]!='\0'){
        if(exp[i]=='(')
        exp[i]=')';
        else if(exp[i]==')')
        exp[i]='(';

    i++;
    }
}

void InfixtoPrefix (char *exp)
{

  int size = strlen (exp);

  
  reverse (exp);
  
  brackets (exp);
  
  covertInfixToPostfix (exp);
  
  reverse (exp);
}

int main ()
{
  printf ("The infix is: ");

  char expression[] = "((a/b)+c)-(d+(e*f))";
  printf ("%s\n", expression);
  InfixtoPrefix (expression);

  printf ("The prefix is: ");
  printf ("%s\n", expression);

  return 0;
}