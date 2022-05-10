#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//6532 6609 6655

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int * timemergesort(const int original[],int n){
    int * arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        *(arr+i) = original[i];
    }
    // Calculate the time taken
    clock_t t;
    t = clock();
   mergeSort(arr,0,n-1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\ntime taken by merge sort = %f milliseconds\n",time_taken*1000);

    return arr;
}

void bubble_sort(int list[], int n)
{
    int c, d, t;

    for (c = 0 ; c < ( n - 1 ); c++)
    {
        for (d = 0 ; d < n - c - 1; d++)
        {
            if (list[d] > list[d+1])
            {
                /* Swapping */
                t         = list[d];
                list[d]   = list[d+1];
                list[d+1] = t;
            }
        }
    }
}

int * timebubblesort(const int original[],int n){
    int * arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        *(arr+i) = original[i];
    }
    // Calculate the time taken
    clock_t t;
    t = clock();
   bubble_sort(arr,n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\ntime taken by bubble sort = %f milliseconds\n",time_taken*1000);

    return arr;
}

void insertion_Sort(int array[], int n)
{
    int i, element, j;
    for (i = 1; i < n; i++)
    {
        element = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > element)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = element;
    }
}

int * timeinsertionsort(const int original[],int n){
    int * arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        *(arr+i) = original[i];
    }
    // Calculate the time taken
    clock_t t;
    t = clock();
   insertion_Sort(arr,n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\ntime taken by insertion sort = %f milliseconds\n",time_taken*1000);

    return arr;
}

void selection_Sort(int array[], int n)
{
    int i, j, position, swap;
    for(i = 0; i < (n - 1); i++)
    {
        position=i;
        for(j = i + 1; j < n; j++)
        {
            if(array[position]>array[j])
                position=j;
        }
        if(position != i)
        {
            swap=array[i];
            array[i]=array[position];
            array[position]=swap;
        }
    }
}

int * timeselectionsort(const int original[],int n){
    int * arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        *(arr+i) = original[i];
    }
    // Calculate the time taken
    clock_t t;
    t = clock();
   selection_Sort(arr,n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\ntime taken by selection sort = %f milliseconds\n",time_taken*1000);

    return arr;
}

int partition(int* arr,int low,int high){
    int *pivot = (arr+high);
    int leftwall = low-1;
    for (int i = low; i < high; ++i) {
        if (arr[i]<*pivot){
            swap(&arr[i],&arr[++leftwall]);

        }
    }
    swap(pivot,&(arr[++leftwall]));
    return leftwall;
}

void quicksort(int* arr,int low, int high){
    if(low<high){
        int pivotlocation = partition(arr,low,high);
        quicksort(arr,low,pivotlocation-1);
        quicksort(arr,pivotlocation+1,high);
    }
}

int * timequicksort(const int original[],int n){
    int * arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        *(arr+i) = original[i];
    }// Calculate the time taken
    clock_t t;
    t = clock();
    quicksort(arr,0,n-1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\ntime taken by quick sort = %f milliseconds\n",time_taken*1000);

    return arr;
}

 void heapify(int arr[], int n, int i) {
    int max = i; //Initialize max as root
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    //If left child is greater than root
    if (leftChild < n && arr[leftChild] > arr[max])
      max = leftChild;

    //If right child is greater than max
    if (rightChild < n && arr[rightChild] > arr[max])
      max = rightChild;

    //If max is not root
    if (max != i) {
      swap(&arr[i], &arr[max]);
      //heapify the affected sub-tree recursively
      heapify(arr, n, max);
    }
  }

  //Main function to perform heap sort
  void heapSort(int arr[], int n) {
    //Rearrange array (building heap)
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    //Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]); //Current root moved to the end

      heapify(arr, i, 0); //calling max heapify on the heap reduced
    }
  }

int * timeheapsort(const int original[],int n){
    int * arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        *(arr+i) = original[i];
    }
    // Calculate the time taken
    clock_t t;
    t = clock();
   heapSort(arr,n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\ntime taken by heap sort = %f milliseconds\n",time_taken*1000);

    return arr;
}

int  *arraygenerator(int n){
    int * arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand();
    }
    return arr;
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{     srand(time(NULL));
    int num []= {1000, 10000, 100000, 200000, 300000, 400000, 500000};
    for (int i = 0; i < 7; ++i) {
        int n = num[i];
        printf("\nNumber of array elements = %d\n",n);
        int *originalarr = arraygenerator(n);

        int*arr=timequicksort(originalarr,n);
        int*arr2=timeselectionsort(originalarr,n);
        int*arr3=timeheapsort(originalarr,n);
        int*arr4=timeinsertionsort(originalarr,n);
        int*arr5=timebubblesort(originalarr,n);
        int*arr6=timemergesort(originalarr,n);
        free(originalarr);
        free(arr);
        free(arr2);
        printf("-----------------------------------------------");
    }
    /*int arr[] = {85, 24, 63, 45, 17, 31, 96, 50};
    int choice,again;
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printf("Given array is : ");
    printArray(arr, arr_size);
    printf("\nSorting by Quick Sort:");
    printf("\n---------------------\n");
        mergeSort(arr, 0, arr_size - 1);
        bubble_sort(arr,arr_size);
        selection_Sort(arr,arr_size);
        insertion_Sort(arr,arr_size);
        heapSort(arr,arr_size);
        quicksort(arr,0,arr_size-1);
        printf("\nSorted array is : ");
        printArray(arr, arr_size);*/

    return 0;
}
