#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define CONSTANT 1000000
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
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
    quickSort(arr, 0, CONSTANT - 1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("%f ms \n", time_taken*1000);
    return 0;
}

