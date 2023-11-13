#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Actselect(int s[], int f[],int n){
int i,j;
i=0;

cout<<i<<" ";

for(j=1;j<n;j++){
    if(s[j]>=f[i]){
        cout<<j<<" ";
        i=j;
    }
  }
}

//driver code
int main(){
int s[] = {1,3 ,0,7 ,9 ,4};
int f[] = {2, 5 ,6 ,9 , 1 ,4};
int n = sizeof(s)/sizeof(s[0]);
Actselect(s,f,n);
return 0;

}
