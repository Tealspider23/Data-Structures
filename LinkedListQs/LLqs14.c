#include <stdio.h>
#include <stdlib.h>

// Array of Linked Lists 

typedef struct node{
    int data;
    struct node*next;
}node;




int main(){
    int n;
    printf("Enter size :");
    scanf("%d",&n);
    
    node**head;

    head = (node*)malloc(n);

    //Initialising to NULL
    for ( int i = 0; i < n; i++)
    {
        *(head+i)=NULL;
    }

    for(int j=0;j<n;j++){
        
        //for last node identification 
        node*prev=NULL;

       int s=4;

        while(s--){

            node* temp = (node*)malloc(sizeof(node));
            temp->data=j*s;
            temp->next=NULL;

            if(*(head+j)==NULL){
                *(head+j)=temp;
            }
            else{
                prev->next=temp;
            }
            prev=temp;
        }

    }

    for(int i =0;i<n;i++){
        node*link=*(head+i);

        while(link!=NULL){
            printf("%d",link->data);
            link=link->next;
        }
        printf("\n");
    }
    return 0;
}
