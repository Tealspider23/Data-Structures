#include<stdio.h>  
int temp;
void heapify(int arr[], int size, int i)
{
int max = i;
int left = 2*i + 1;
int right = 2*i + 2;

if (left < size && arr[left] >arr[max])
max= left;

if (right < size && arr[right] > arr[max])
max= right;

if (max!= i)
{

temp = arr[i];
arr[i]= arr[max];
arr[max] = temp;
heapify(arr, size, max);
}
}

void heapSort(int arr[], int size)
{
int i;
for (i = size / 2 - 1; i >= 0; i--)
heapify(arr, size, i);
for (i=size-1; i>=0; i--)
{

temp = arr[0];
arr[0]= arr[i];
arr[i] = temp;
heapify(arr, i, 0);
}
}

void main() 
{
int arr[] = {12,99,87,23,67,35,102,55,19};

int i;
int size = sizeof(arr)/sizeof(arr[0]);

heapSort(arr, size);

printf("printing sorted elements\n"); 
for (i=0; i<size; ++i)
printf("%d ",arr[i]);
}