#include <stdio.h>

//Write an algorithm to merge two sorted array into one array

int main(){

int A[4]={15,25,35,45};
int B[4]={10,20,30,40};
int C[8];
int index=0;
int i=0;
int j=0;
int k=0;


while(A[i]!=B[j]){
    if(A[i]<B[j]){
    C[index]=A[i];
    i++;
    index++;
}else{
C[index]=B[j];
j++;
index++;}
}

while(i<4){
    C[index]=A[i];
    i++;
    index++;
}
while(j<4){
    C[index]=B[j];
    j++;
    index++;}


for(k=0;k<8;k++){
printf("%d ",C[k]);
}











return 0;


}
