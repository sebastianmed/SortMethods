
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CONSTANT 1000000
int main()
{
    int myArray[CONSTANT];
    int i, j;
    int temp = 0;
    int num;
    clock_t t;
    //srand(time(NULL));
    
    //fill array
    for (i = 0; i < CONSTANT; i ++)
    {
        num = rand() % CONSTANT + 1;
        myArray[i] = num;
    }
    
    t = clock();
    //sort array
    for(i = 0; i < CONSTANT; i++)
    {
        
        for (j = 0; j < CONSTANT-1; j++)
        {
            if (myArray[j] > myArray[j+1])
            {
                temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }
        }/*End inner for loop*/
    }/*End outer for loop*/
    t = clock() - t;

    float time_taken = ((float)t)/CLOCKS_PER_SEC; // in seconds
    printf("%.10lf ms \n", (time_taken)*1000);

    
    
    //print array
   // for (i = 0; i < BUBBLE; i++)
   // {
    //    printf("%d\n",myArray[i]);
    //}
    
    //system("PAUSE");
    return 0;
}/*End of main*/
