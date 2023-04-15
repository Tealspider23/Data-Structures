#include <stdio.h>
#include <stdlib.h>

void createList(struct node **head, int n)
{
    int i, data;
    struct node *prevNode, *newNode;

    prevNode = NULL;
    newNode  = NULL;


    /* Creates and links rest of the n-1 nodes */
    for(i=1; i<=n; i++)
    {
        // Create a new node
        newNode = (struct node *) malloc(sizeof(struct node));

        printf("Enter data of %d node: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        // Link the previous node with newly created node
        if (prevNode != NULL)
            prevNode->next = newNode;

        // Move the previous node ahead
        prevNode = newNode;

        // Link head node if not linked
        if (*head == NULL)
            *head = newNode;
    }

    // Link last node with first node
    prevNode->next = *head;

    printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
}