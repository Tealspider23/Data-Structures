#include <stdio.h>
#include <stdlib.h>


int max(int a, int b);

int lcs(char* A, char* B, int i, int j)
{
    if (A[i]==0 || B[j]==0){
        return 0;
    }
    if (A[i]==B[j]){
        return 1+lcs(A,B,i+1,j+1);
        }
    else{
        return max(lcs(A,B,i,j+1),
                   lcs(A,B,i+1,j));
        }
}


int max(int a, int b) {
    return (a > b) ? a : b;
     }


int main()
{
    char S1[] = "ABCDEFGH";
    char S2[] = "ABCDH";
    int m = strlen(S1);
    int n = strlen(S2);
    int i = 0, j = 0;
    printf("Length of LCS is %d", lcs(S1, S2, i, j));

    return 0;

}
