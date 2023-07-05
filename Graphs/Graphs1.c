#include <stdio.h>
#include <stdlib.h>


//BFS Traversal in a Graph

//BFS is a traversing algorithm where you should start traversing 
//from a selected node (source or starting node) and 
//traverse the graph layerwise thus exploring the neighbour
// nodes (nodes which are directly connected to source node).
// You must then move towards the next-level neighbour nodes.


//BFS is implemented using Queue Data Structure

//BFS Algorithm
//1)Create a queue and enqueue source into it.
//2)While queue is not empty, do following
//  a)Dequeue a vertex from queue. Let this be v.
//  b)Print v   
//  c)Enqueue all not yet visited neighbours of v
//    and mark them visited.

//Time Complexity: O(V+E) where V is number of vertices in the graph 
//and E is number of edges in the graph.

//Space Complexity: O(V).

//Code for BFS traversal in Graph

//Graph Implementation using Adjacency List

//A structure to represent an adjacency list node

 typedef struct AdjacentListNode{
    int dest;
    struct AdjacentListNode* next;
}AdjacentListNode;

//A structure to represent an adjacency list
 
typedef struct AdjacentList{
    struct AdjacentListNode* head;
}AdjacentList;

//A structure to represent a graph. A graph is an array of adjacency lists.

typedef struct Graph{
    int V;
    struct AdjacentList* array;
}Graph;

//A utility function to create a new adjacency list node

AdjacentListNode* newAdjacentListNode(int dest){
    AdjacentListNode* newnode = (AdjacentListNode*)malloc(sizeof(AdjacentListNode));
    newnode->dest = dest;
    newnode->next = NULL;
    return newnode;
}

//A utility function that creates a graph of V vertices

Graph* createGraph(int V){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjacentList*)malloc(sizeof(AdjacentList)*V);
    for(int i = 0; i < V ; i++){
        graph->array[i].head = NULL;
    }
    return graph;
}

//Adds an edge to an undirected graph

void addEdge(Graph* graph , int src , int dest){
    AdjacentListNode* newnode = newAdjacentListNode(dest);
    newnode->next = graph->array[src].head;
    graph->array[src].head = newnode;
    
    newnode = newAdjacentListNode(src);
    newnode->next = graph->array[dest].head;
    graph->array[dest].head = newnode;
}

//A utility function to print the adjacency list representation of graph

void printGraph(Graph* graph){
    for(int i = 0 ; i < graph->V ; i++){
        AdjacentListNode* temp = graph->array[i].head;
        printf("Adjacency list of vertex %d\n head ", i);
        while(temp){
            printf("-> %d",temp->dest);
            temp= temp->next;
        }
        printf("\n");
    }
}

//A utility function to create a new Queue Node

typedef struct QueueNode{
    int data;
    struct QueueNode* next;
}QueueNode;

//A utility function to create an empty Queue

typedef struct Queue{
    struct QueueNode* front;
    struct QueueNode* rear;
}Queue;

QueueNode* newQueueNode(int data){
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

Queue* createQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

//The function to add a key k to q

void enqueue(Queue* queue , int data){
    QueueNode* newnode = newQueueNode(data);
    if(queue->rear == NULL){
        queue->front = queue->rear = newnode;
        return;
    }
    queue->rear->next = newnode;
    queue->rear = newnode;
}

//Function to remove a key from given queue q

int dequeue(Queue* queue){
    if(queue->front == NULL){
        return -1;
    }
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}

//Function to check if queue is empty

int isEmpty(Queue* queue){
    if(queue->front == NULL){
        return 1;
    }
    return 0;
}

//Function to do BFS traversal of graph

void BFS(Graph* graph , int src){
     int visited[graph->V];
     for(int i = 0 ; i<graph->V ; i++){
        visited[i]=0;
     }
     Queue* q = createQueue();
      visited[src]= 1;
      enqueue(q,src);
      while(!isEmpty(q)){
        int u = dequeue(q);
        printf("%d", u);
        AdjacentListNode* temp = graph->array[u].head;
        while(temp){
            if(visited[temp->dest] == 0){
                visited[temp->dest]=1;
                enqueue(q,temp->dest);
            }
            temp = temp->next;

        }
      }
}

//Driver Program to test above functions

int main(){
    int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    printGraph(graph);
    BFS(graph,2);
    return 0;
}

