#include <stdio.h>
#include <limits.h>

int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k)
                + MatrixChainOrder(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }
    return min;
}


int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d ",
           MatrixChainOrder(arr, 1, N - 1));
    getchar();
    return 0;
}

