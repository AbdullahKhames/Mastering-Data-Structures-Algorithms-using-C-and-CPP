#include "main.h"

void findDuplicatesSorted(Array *array)
{
    int lastDuplicate = INT_MIN;
    for (int i = 0; i < array->length - 1; i++)
    {
        if (array->arr[i] == array->arr[i + 1] && array->arr[i] != lastDuplicate)
        {
            lastDuplicate = array->arr[i];
            printf("%d\n", lastDuplicate);
        }
    }
}
void findAndCountMultipleDuplicatesSorted(Array *array)
{
    int counter = 0, i = 0;
    while (i < array->length - 1)
    {
        counter = 1;
        while (i < array->length - 1 && array->arr[i] == array->arr[i + 1])
        {
            i++;
            counter++;
        }
        if (counter > 1)
        {
            printf("element %d was repeated %d times\n", array->arr[i], counter);
        }
        i++;
    }
}
void findAndCountMultipleDuplicatesNotSorted(Array *array)
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
        if (newArray->arr[i] > 1)
        {
            printf("element %d was repeated %d times\n", i, newArray->arr[i]);
        }
    }
    free(newArray);
}
