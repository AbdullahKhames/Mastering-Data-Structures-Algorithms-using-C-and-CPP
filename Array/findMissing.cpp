#include "main.h"

/**
 * findMissingSorted: a function to find and prints one missing element from a sorted array
 * @array: the pointer to the array structure u want to search
 */
void findMissingSorted(Array *array)
{
    int max = array->arr[array->length - 1];
    int naturalSum = max * (max + 1) / 2;
    int actualSum = sum(array);
    printf("%d \n", naturalSum - actualSum);
}
/**
 * findMultipleMissingSorted: a function to find and prints one multiple element from a sorted array
 * @array: the pointer to the array structure u want to search
 */
void findMultipleMissingSorted(Array *array)
{
    int difference = array->arr[0] - 0, i = 1;
    while (i < array->length)
    {
        while (array->arr[i] - i != difference)
        {
            printf("%d\n", difference + i);
            difference++;
        }
        i++;
    }
}

/**
 * findMultipleMissingNotSorted: a function to find and prints multiple missing element from a un sorted array
 * @array: the pointer to the array structure u want to search
 */
void findMultipleMissingNotSorted(Array *array)
{
    Array *newArray;
    int size = max(array), low = min(array);
    init(&newArray, size, 1);
    newArray->length = size;
    for (int i = 0; i < array->length; i++)
    {
        newArray->arr[array->arr[i]]++;
    }
    for (int i = low; i < size; i++)
    {
        if (newArray->arr[i] == 0)
        {
            printf("%d\n", i);
        }
    }
    free(newArray);
}
