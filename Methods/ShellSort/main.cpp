#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define CONSTANT 10
using namespace std;

int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            arr[j] = temp;
        }
    }
    return 0;
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
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
    shellSort(arr, CONSTANT);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("%f ms \n", time_taken*1000);
    
    //printArray(arr, BUBBLE);
    
    return 0;
}

