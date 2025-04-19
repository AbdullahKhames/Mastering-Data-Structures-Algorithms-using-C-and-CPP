#include "main.h"

/**
 * init: function initialized the int array inside the array struct with the wanted size
 * and each index is holding the int min value
 *
 * @array: the array struct to be initialized
 *          the length will be 0 and size will be size var
 * @size: the size to assign to the array
 * @allZeros: if 0 it won't initialize to 0 but will initialize all to be INT_MIN
 *              else if equal to 0 it will initialize all to elements to equal 0
 */
void init(Array **array, int size, int allZeros)
{
    *array = (Array *)malloc(sizeof(Array));
    (*array)->arr = (int *)malloc(sizeof(int) * size);
    init((*array)->arr, size, NULL, NULL, allZeros);
    (*array)->size = size;
    (*array)->length = 0;
}
/**
 * init: helper function to initialize each index of the array either to INT_MIN
 *          or to the old value from the oldArray
 *
 * @array: the array struct to be initialized
 *          the length will be 0 and size will be size var
 * @size: the size to assign to the array
 * @oldArray: the old array to copy items from
 * @oldSize: the length of the old array to be copied from
 * @allZeros: if 0 it won't initialize to 0 but will initialize all to be INT_MIN
 *              else if equal to 0 it will initialize all to elements to equal 0
 */
void init(int *array, int size, int oldArray[], int oldSize, int allZeros)
{
    if (!oldArray)
    {
        for (int i = 0; i < size; i++)
        {
            if (allZeros == 0)
            {
                array[i] = INT_MIN;
            }
            else
            {
                array[i] = 0;
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (i < oldSize)
            {
                array[i] = oldArray[i];
            }
            if (i >= oldSize && allZeros == 1)
            {
                array[i] = 0;
            }
            else
            {
                array[i] = INT_MIN;
            }
        }
        free(oldArray);
    }
}

/**
 * display: takes in an array address and based on its length variable
 *           it displays each element
 */
void display(Array *array)
{
    for (int i = 0; i < array->length; i++)
    {
        printf("%d ", array->arr[i]);
    }
    printf("\n");
}

/**
 * add: appends an element to the end of the array
 * @x: the element to be added
 */
void add(Array *array, int x)
{
    if (array->length == array->size)
    {
        doubleGrow(array);
    }
    array->arr[array->length] = x;
    array->length++;
}

/**
 * doubleGrow: function to grow the inner array by double
 * @array: the address of the array object
 *          to increase its array reference size by double
 */
void doubleGrow(Array *array)
{
    if (array->size <= 0)
    {
        array->size = 1;
    }
    int size = array->size * 2;
    printf("increasing the size of array from %d to %d\n", array->size, size);
    int *oldArr = array->arr;
    int *newArr = (int *)malloc(sizeof(int) * size);
    array->arr = newArr;
    init(newArr, size, oldArr, array->size, 0);
    array->size = size;
}

/**
 * insert: function to insert to the array reference an element x at given index
 * @array: the address of the array object
 *          to insert into the index
 *          and shift elements to the right from the start index
 * @index: index to be inserted in
 * @X: the element to be inserted
 */
void insert(Array *array, int index, int x)
{
    if (index >= 0 && index < array->length)
    {
        for (int i = array->length; i > index; i--)
        {
            array->arr[i] = array->arr[i - 1];
        }
        array->arr[index] = x;
        array->length++;
    }
    else if (index >= array->length)
    {
        add(array, x);
    }
}

/**
 * remove: function to remove from the array reference in a given index
 * @array: the address of the array object
 *          to remove from the index
 *          and shift elements to the left from the start index
 * @index: the index to be removed from
 */
int remove(Array *array, int index)
{
    int removed = array->arr[index];
    for (int i = index; i < array->length; i++)
    {
        array->arr[i] = array->arr[i + 1];
    }
    array->length--;
    array->arr[array->length] = INT_MIN;
    return removed;
}

/**
 * linearSearch: function to search the array for a given item
 * @array: the array to search
 * @item: the search item
 * return: return the index of the item if found
 *          else return -1
 */
int linearSearch(Array *array, int item)
{
    for (int i = 0; i < array->length; i++)
    {
        if (array->arr[i] == item)
        {
            return i;
        }
    }
    return -1;
}

/**
 * binarySearch: iterative function to search the array for a given item
 * @array: the array to search must be sorted
 * @item: the search item
 * return: return the index of the item if found
 *          else return -1
 */
int binarySearch(Array *array, int item)
{
    int left = 0, right = array->length - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (array->arr[mid] == item)
        {
            return mid;
        }
        if (array->arr[mid] > item)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}
/**
 * recursiveBinarySearch: recursive function to search the array for a given item
 * @array: the array to search must be sorted
 * @item: the search item
 * return: return the index of the item if found
 *          else return -1
 */
int recursiveBinarySearch(Array *array, int item)
{
    int left = 0, right = array->length - 1;
    return rBinarySearch(array->arr, left, right, item);
}
/**
 * rBinarySearch: the recursive function that actually get the index of the searched item
 * @array: the array to search
 * @left: the index at which to start search at first call it is 0
 * @right: the index at which to stop search at first call it is length - 1
 * @item: the search item
 * return: return the index of the item if found
 *          else return -1
 */
int rBinarySearch(int *array, int left, int right, int item)
{
    if (left > right)
    {
        return -1;
    }
    else
    {
        int mid = left + (right - left) / 2;
        if (array[mid] == item)
        {
            return mid;
        }
        else if (array[mid] > item)
        {
            return rBinarySearch(array, left, mid - 1, item);
        }
        else
        {
            return rBinarySearch(array, mid + 1, right, item);
        }
    }
}

/**
 * get: a function to get item at given index from the array
 * @array: the array to be used
 * @index: the index you want to get must be a valid index
 *          i.e between 0 and length - 1
 * return: the element if index is valid else returns INT_MIN
 */
int get(Array *array, int index)
{
    if (index >= 0 && index < array->length - 1)
    {
        return array->arr[index];
    }
    return INT_MIN;
}

/**
 * set: a function to set to a given array a given item at a given index replace the old value
 * @array: the array struct to be modified
 * @index: index at which to set the value 0 based
 * @x: the element to be added
 * return: returns the element or INT_MIN if failed
 */
int set(Array *array, int index, int x)
{
    if (index >= 0 && index < array->length - 1)
    {
        array->arr[index] = x;
        return x;
    }
    return INT_MIN;
}

/**
 * max: a function gets the maximum element present in an array
 * @array: array to be searched
 * return: returns the value of the max element in the array or INT_MIN if no elements
 */
int max(Array *array)
{
    int max = INT_MIN;
    for (int i = 0; i < array->length; i++)
    {
        if (array->arr[i] > max)
        {
            max = array->arr[i];
        }
    }
    return max;
}

/**
 * min: a function gets the minimum element present in an array
 * @array: array to be searched
 * return: returns the value of the min element in the array or INT_MAX if no elements
 */
int min(Array *array)
{
    int min = INT_MAX;
    for (int i = 0; i < array->length; i++)
    {
        if (array->arr[i] < min)
        {
            min = array->arr[i];
        }
    }
    return min;
}

/**
 * sum: a function to get the sum of all the elements in the array
 * @array: the array to be looped through
 * Return: returns the sum of all elements in the array or 0 if no elements
 */
int sum(Array *array)
{
    int sum = 0;
    for (int i = 0; i < array->length; i++)
    {
        sum += array->arr[i];
    }
    return sum;
}

/**
 * avg: a function to get the average of the elements in the array
 * @array: the array to be looped through
 * Return: returns the avg of all elements in the array or 0 if no elements
 */
float avg(Array *array)
{
    return (float)sum(array) / array->length;
}

/**
 * reverseAuxillaryArray: reverses an array by utilizing an auxillary array
 * @array: the array to be reversed
 */
void reverseAuxillaryArray(Array *array)
{
    int count = array->length;
    int *aux = (int *)malloc(sizeof(int) * count);
    for (int i = 0, j = count - 1; i < count; i++, j--)
    {
        aux[i] = array->arr[j];
    }
    for (int i = 0; i < count; i++)
    {
        array->arr[i] = aux[i];
    }
    free(aux);
}
/**
 * swap: a function to swap array elements based on their position
 * arr: the array to be manipulated
 * @i: index of the first item to be swapped
 * @j: the index of the second item to be swapped
 */
void swap(int *arr, int i, int j)
{
    int temp;

    if (!arr)
    {
        return;
    }
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/**
 * reverseTwoPointers: reverses an array by utilizing a 2 pointers approach
 * @array: the array to be reversed
 */
void reverseTwoPointers(Array *array)
{
    for (int i = 0, j = array->length - 1; i < j; i++, j--)
    {
        swap(array->arr, i, j);
    }
}

/**
 * leftShift: a function to left shift an array
 * @array: the array to be shifted
 */
void leftShift(Array *array)
{
    for (int i = 0; i < array->length - 1; i++)
    {
        array->arr[i] = array->arr[i + 1];
    }
    array->arr[array->length - 1] = 0;
}

/**
 * leftRotate: a function to leftRotate an array
 * @array: the array to be leftRotate
 */
void leftRotate(Array *array)
{
    int left = array->arr[0];
    leftShift(array);
    array->arr[array->length - 1] = left;
}

/**
 * rightShift: a function to rightShift an array
 * @array: the array to be rightShift
 */
void rightShift(Array *array)
{
    for (int i = array->length - 1; i > 0; i--)
    {
        array->arr[i] = array->arr[i - 1];
    }
    array->arr[0] = 0;
}

/**
 * rightRotate: a function to rightRotate an array
 * @array: the array to be rightRotate
 */
void rightRotate(Array *array)
{
    int right = array->arr[array->length - 1];
    rightShift(array);
    array->arr[0] = right;
}

/**
 * insert: function to insert in a sorted list based on the value it dynamically
 *          knows where to add the value
 * @arr: the array struct to add to its array object
 * @x: the element to be added
 */
void insert(Array *arr, int x)
{
    // int index = arr->length;
    // for (int i = 0; i < arr->length - 1; i++)
    // {
    //     if (x > arr->arr[i] && x <= arr->arr[i + 1])
    //     {
    //         index = i + 1;
    //     }
    // }
    // insert(arr, index, x);
    if (arr->length == arr->size)
    {
        doubleGrow(arr);
    }

    for (int i = arr->length; i > 0; i--)
    {
        if (arr->arr[i - 1] > x)
        {
            arr->arr[i] = arr->arr[i - 1];
        }
        else
        {
            arr->arr[i] = x;
            arr->length++;
            return;
        }
    }
    arr->arr[0] = x;
    arr->length++;
    // int i = arr->length - 1;
    // while (arr->arr[i] > x)
    // {
    //     arr->arr[i + 1] = arr->arr[i];
    //     i--;
    // }
    // arr->arr[i + 1] = x;
    // arr->length++;
}

/**
 * isSorted: a function to check if an array is sorted or not
 * @arr: the array to be checked
 */
int isSorted(Array *arr)
{
    bool asc = arr->arr[0] <= arr->arr[1];
    for (int i = 1; i < arr->length - 1; i++)
    {
        if (asc)
        {
            if (arr->arr[i] > arr->arr[i + 1])
            {
                return 0;
            }
        }
        else
        {
            if (arr->arr[i] < arr->arr[i + 1])
            {
                return 0;
            }
        }
    }
    return 1;
}

/**
 * reArrange re arranges an array to have all of its negative numbers on the left
 *          and the positive on the right
 * @arr: array to be arranged
 */
void reArrange(Array *arr)
{
    int left = 0, right = arr->length - 1;
    while (left < right)
    {
        while (arr->arr[left] < 0)
        {
            left++;
        }
        while (arr->arr[right] >= 0)
        {
            right--;
        }
        if (left < right)
        {
            swap(arr->arr, left, right);
        }
    }
}

/**
 * mergeTwoSortedArrays: merges two sorted array into a new merged sorted array
 *                          keeping the original sorting
 * @array1: the first array
 * @array2: the second array
 * return: returns the newly created array holder
 */
Array *mergeTwoSortedArrays(Array *array1, Array *array2)
{
    Array *newArray;
    int size = array1->size + array2->size;
    int length = array1->length + array2->length;
    init(&newArray, size, 0);
    newArray->length = length;

    int firstArrayIdx = 0, secondArrayIdx = 0, newArrayIdx = 0;

    while (firstArrayIdx < array1->length && secondArrayIdx < array2->length)
    {
        if (array1->arr[firstArrayIdx] <= array2->arr[secondArrayIdx])
        {
            newArray->arr[newArrayIdx++] = array1->arr[firstArrayIdx++];
        }
        else
        {
            newArray->arr[newArrayIdx++] = array2->arr[secondArrayIdx++];
        }
    }

    while (firstArrayIdx < array1->length)
    {
        newArray->arr[newArrayIdx++] = array1->arr[firstArrayIdx++];
    }
    while (secondArrayIdx < array2->length)
    {
        newArray->arr[newArrayIdx++] = array2->arr[secondArrayIdx++];
    }
    return newArray;
}
/**
 * unionMerged: finds the union between the two arrays
 * @array1: the first array
 * @array2: the second array
 * return: returns the newly created array holder
 */
Array *unionMerged(Array *array1, Array *array2)
{
    Array *newArray;
    int size = array1->size + array2->size;
    init(&newArray, size, 0);

    int firstArrayIdx = 0, secondArrayIdx = 0, newArrayIdx = 0;

    while (firstArrayIdx < array1->length && secondArrayIdx < array2->length)
    {
        if (array1->arr[firstArrayIdx] < array2->arr[secondArrayIdx])
        {
            newArray->arr[newArrayIdx++] = array1->arr[firstArrayIdx++];
        }
        else if (array1->arr[firstArrayIdx] > array2->arr[secondArrayIdx])
        {
            newArray->arr[newArrayIdx++] = array2->arr[secondArrayIdx++];
        }
        else
        {
            newArray->arr[newArrayIdx++] = array1->arr[firstArrayIdx++];
            secondArrayIdx++;
        }
    }

    while (firstArrayIdx < array1->length)
    {
        newArray->arr[newArrayIdx++] = array1->arr[firstArrayIdx++];
    }
    while (secondArrayIdx < array2->length)
    {
        newArray->arr[newArrayIdx++] = array2->arr[secondArrayIdx++];
    }
    newArray->length = newArrayIdx;

    return newArray;
}
/**
 * intersectionMerged: finds the intersection between two sorted sets
 * @array1: the first array
 * @array2: the second array
 * return: returns the newly created array holder
 */
Array *intersectionMerged(Array *array1, Array *array2)
{
    Array *newArray;
    int size = array1->size + array2->size;
    init(&newArray, size, 0);

    int firstArrayIdx = 0, secondArrayIdx = 0, newArrayIdx = 0;
    while (firstArrayIdx < array1->length && secondArrayIdx < array2->length)
    {
        if (array1->arr[firstArrayIdx] == array2->arr[secondArrayIdx])
        {
            newArray->arr[newArrayIdx++] = array1->arr[firstArrayIdx++];
            secondArrayIdx++;
        }
        else
        {
            firstArrayIdx++;
            secondArrayIdx++;
        }
    }

    newArray->length = newArrayIdx;
    return newArray;
}
/**
 * differenceMerged: finds the difference between two sorted sets
 * @array1: the first array
 * @array2: the second array
 * return: returns the newly created array holder
 */
Array *differenceMerged(Array *array1, Array *array2)
{
    Array *newArray;
    int size = array1->size + array2->size;
    init(&newArray, size, 0);

    int firstArrayIdx = 0, secondArrayIdx = 0, newArrayIdx = 0;
    while (firstArrayIdx < array1->length && secondArrayIdx < array2->length)
    {
        if (array1->arr[firstArrayIdx] == array2->arr[secondArrayIdx])
        {
            firstArrayIdx++;
            secondArrayIdx++;
        }
        else if (array1->arr[firstArrayIdx] < array2->arr[secondArrayIdx])
        {
            newArray->arr[newArrayIdx++] = array1->arr[firstArrayIdx++];
        }
        else
        {
            secondArrayIdx++;
        }
    }
    while (firstArrayIdx < array1->length)
    {
        newArray->arr[newArrayIdx++] = array1->arr[firstArrayIdx++];
    }

    newArray->length = newArrayIdx;
    return newArray;
}
