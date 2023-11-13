#include <stdio.h>

int main(){
int arr[7]={10,20,30,40,60,70};
int a;

printf("Enter the element you want to search.");
scanf("%d",&a);

int i;
for(i=0;i<7;i++){
 if(arr[i]==a){
    printf("Element found at Index - %d",i);
 }
}


return 0;

}



