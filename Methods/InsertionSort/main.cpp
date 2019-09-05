

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CONSTANT 1000000

using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
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
    insertionSort(arr, CONSTANT);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("%f ms \n", time_taken*1000);
    //printArray(arr, BUBBLE);
    
    return 0;
}


