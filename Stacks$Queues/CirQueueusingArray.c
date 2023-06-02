#include<stdio.h>

#define capacity 6

int queue[capacity];
int front = -1, rear = -1;

// Here we check if the Circular queue is full or not
int checkFull ()
{
  if ((front == rear + 1) || (front == 0 && rear == capacity - 1))
    {
      return 1;
    }
  return 0;
}

// Here we check if the Circular queue is empty or not
int checkEmpty ()
{
  if (front == -1)
    {
      return 1;
    }
  return 0;
}

// Addtion in the Circular Queue
void enqueue (int value)
{
  if (checkFull ())
    printf ("Overflow condition\n");

  else
    {
      if (front == -1)
	front = 0;

      rear = (rear + 1) % capacity;
      queue[rear] = value;
      printf ("%d was enqueued to circular queue\n", value);
    }
}

// Removal from the Circular Queue
int dequeue ()
{
  int variable;
  if (checkEmpty ())
    {
      printf ("Underflow condition\n");
      return -1;
    }
  else
    {
      variable = queue[front];
      if (front == rear)
	{
	  front = rear = -1;
	}
      else
	{
	  front = (front + 1) % capacity;
	}
      printf ("%d was dequeued from circular queue\n", variable);
      return 1;
    }
}

// Display the queue
void print ()
{
  int i;
  if (checkEmpty ())
    printf ("Nothing to dequeue\n");
  else
    {
      printf ("\nThe queue looks like: \n");
      for (i = front; i != rear; i = (i + 1) % capacity)
	{
	  printf ("%d ", queue[i]);
	}
      printf ("%d \n\n", queue[i]);

    }
}

int main ()
{
  // Not possible as the Circular queue is empty
  dequeue ();

  enqueue (15);
  enqueue (20);
  enqueue (25);
  enqueue (30);
  enqueue (35);

  print ();
  dequeue ();
  dequeue ();

  print ();

  enqueue (40);
  enqueue (45);
  enqueue (50);
  enqueue (55);			//Overflow condition
  print ();

  return 0;
}
