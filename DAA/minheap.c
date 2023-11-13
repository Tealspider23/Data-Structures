void swap(int*a , int*b){
int temp =*a;
*a = *b;
*b = temp;
}
//Max Heap sort
void heapify(int arr[],int N , int i ){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<N && arr[left]<arr[smallest]){
        smallest = left;
    }
    if(right < N && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest!=i){
        swap(&arr[i],&arr[smallest]);
        heapify(arr,N , smallest);
    }
}


void heapsort(int arr[], int N){
{
int i;

    for ( i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
}

void printArray(int arr[], int N)
{
    int i;
    for ( i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);

    return 0;
}


