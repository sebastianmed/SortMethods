#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <vector>

#define CONSTANT 100000
using namespace std;

static void BucketSort(int* data, int count) {
    int minValue = data[0];
    int maxValue = data[0];
    
    for (int i = 1; i < count; i++)
    {
        if (data[i] > maxValue)
            maxValue = data[i];
        if (data[i] < minValue)
            minValue = data[i];
    }
    
    int bucketLength = maxValue - minValue + 1;
    vector<int>* bucket = new vector<int>[bucketLength];
    
    for (int i = 0; i < bucketLength; i++)
    {
        bucket[i] = vector<int>();
    }
    
    for (int i = 0; i < count; i++)
    {
        bucket[data[i] - minValue].push_back(data[i]);
    }
    
    int k = 0;
    for (int i = 0; i < bucketLength; i++)
    {
        int bucketSize = bucket[i].size();
        
        if (bucketSize > 0)
        {
            for (int j = 0; j < bucketSize; j++)
            {
                data[k] = bucket[i][j];
                k++;
            }
        }
    }
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
    BucketSort(arr, CONSTANT);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f ms \n", time_taken*1000);

    
    return 0;
}
