#include <stdio.h>
#include <stdlib.h>

//Swapping nodes of linked list
 struct Treenode{
    int data ;
    struct Treenode* next;
}*head=NULL;

typedef struct Treenode Treenode ;

void display(Treenode*head){
    Treenode *temp=head;
    while(temp->next!=NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}

Treenode * createLL(int size )
{
    Treenode * temp =NULL ; 
    Treenode * ptr = NULL ; 
    int data;

    for (int i = 0 ; i< size ; i++)
    {
        temp = (Treenode*)malloc(sizeof(Treenode));
        printf("Enter Data into Nodes");
        scanf("%d", &data);
        temp->data=data;

        temp->next=NULL;

        if (head == NULL)
        {
            head = temp ; 
        }
        else{
            ptr = head ;
            while(ptr->next!=NULL)
            ptr = ptr->next ; 
            ptr->next = temp ;
        }

    }
    return head ; 

}

int calcsize(Treenode*head){
    Treenode*temp =head;
    int count =0;

    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    return count;

}
 
int swap(struct Treenode*head,int pos1 , int pos2){

    Treenode* node1, *node2,*prev1,*prev2,*temp;
    int i;

    int size = calcsize(head);

    const int maxpos=(pos1>pos2)?pos1:pos2;

    if((pos1<=0 || pos1>size ) || (pos2<=0 || pos2>size)){
        return -1;
    }

    if(pos1==pos2){
        return 1;
    }

    prev1=NULL;
    prev2=NULL;
    i=1;

    while(temp!=NULL && i<=size){

        if(i==pos1-1){
            prev1=temp;
        }
        if(i==pos1){
            node1=temp;
        }
        if(i==pos2-1){
            prev2=temp;
        }
        if(i==pos2){
            node2=temp;
        }
        temp=temp->next;
        i++;
    }

    if(node1!=NULL && node2!=NULL){


        if(prev1!=NULL){
            prev1->next = node2;
        }

        if(prev2!=NULL){
            prev2->next = node1;
        }

        temp=node1->next;
        node1->next = node2->next;
        node2->next = temp;


        //Updating Head if prev == NULL 

        if(prev1==NULL){
            head=node2;
        }
        else if (prev2==NULL){
            head =node1;
        }
    }

        return 1;


}

int main ()
{
    head = createLL(5);
    Treenode*temp;
    int pos1 =2;
    int pos2=4;
   
    if (swap(head, pos1, pos2) == 1)
    {
        printf("\nData \n");
        
        display(head);
    }
    else 
    {
        printf("invalid position\n");
    }



   

    return 0 ;
}

