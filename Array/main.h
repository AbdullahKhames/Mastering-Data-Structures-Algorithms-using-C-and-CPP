#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ArrayStruct
{
    int *arr;
    int length;
    int size;
} Array;

void init(Array **arr, int size, int allZeros);
void init(int *array, int size, int oldArray[], int oldSize, int allZeros);
void display(Array *arr);
void add(Array *arr, int x);
void doubleGrow(Array *arr);
void insert(Array *arr, int index, int x);
int remove(Array *arr, int index);
int linearSearch(Array *arr, int item);
int binarySearch(Array *arr, int item);
int recursiveBinarySearch(Array *array, int item);
int rBinarySearch(int *array, int left, int right, int item);
int get(Array *array, int index);
int set(Array *array, int index, int x);
int max(Array *array);
int min(Array *array);
int sum(Array *array);
float avg(Array *array);
void reverseAuxillaryArray(Array *array);
void reverseTwoPointers(Array *array);
void leftShift(Array *array);
void leftRotate(Array *array);
void rightShift(Array *array);
void rightRotate(Array *array);
void swap(int *arr, int i, int j);
void insert(Array *arr, int x);
int isSorted(Array *arr);
void reArrange(Array *arr);
Array *mergeTwoSortedArrays(Array *array1, Array *array2);
Array *unionMerged(Array *array1, Array *array2);
Array *intersectionMerged(Array *array1, Array *array2);
Array *differenceMerged(Array *array1, Array *array2);
void findMissingSorted(Array *array);
void findMultipleMissingSorted(Array *array);
void findMultipleMissingNotSorted(Array *array);

void findDuplicatesSorted(Array *array);
void findAndCountMultipleDuplicatesSorted(Array *array);
void findAndCountMultipleDuplicatesNotSorted(Array *array);

void printPairTOSum(Array arr, int k);
#endif
