#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define CONSTANT 1000000

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[CONSTANT];
    clock_t t;
    int i, num;
    for (i = 0; i < CONSTANT; i ++)
    {
        num = rand() % CONSTANT + 1;
        arr[i] = num;
    }
    t = clock();
    heapSort(arr, CONSTANT);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("%f ms \n", time_taken*1000);
    
}
