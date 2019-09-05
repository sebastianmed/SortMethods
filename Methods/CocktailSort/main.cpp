
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define CONSTANT 1000000
using namespace std;

void CocktailSort(int a[], int n)
{
    
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    
    while (swapped) {

        swapped = false;

        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;

        --end;

        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

/* Prints the array */
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
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
    CocktailSort(arr,CONSTANT);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f ms \n", time_taken*1000);
    //printArray(arr,BUBBLE);
    return 0;
}
