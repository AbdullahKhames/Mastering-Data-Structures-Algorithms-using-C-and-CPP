#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"


typedef struct Queue
{
    int size;
    int front;
    int rear;
    Tree **Q;
} Queue;

void Create(Queue *q, int size);
int isFull(Queue q);
int isEmpty(Queue q);
void enqueue(Queue *q, Tree *x);
Tree *dequeue(Queue *q);
void Display(Queue q);

#endif
