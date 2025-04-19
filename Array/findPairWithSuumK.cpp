#include "main.h"

void printPairTOSum(Array arr, int k)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.arr[i] + arr.arr[j] == k)
            {
                printf("element %d + element %d = %d\n", arr.arr[i], arr.arr[j], k);
            }
            
        }
    }
    
}
