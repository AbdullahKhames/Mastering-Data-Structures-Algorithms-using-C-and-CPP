#include "Queue.h"

void Create(Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Tree **)malloc(q->size * sizeof(Tree *));
}

int isFull(Queue q)
{
    return (q.rear + 1) % q.size == q.front;
}

int isEmpty(Queue q)
{
    return q.rear == q.front;
}

void enqueue(Queue *q, Tree *x)
{
    if (isFull(*q))
        printf("Queue is full\n");
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

Tree *dequeue(Queue *q)
{
    Tree *x = NULL;
    if (isEmpty(*q))
        printf("Queue is Empty\n");
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}

void Display(Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]->data);
    printf("\n");
}
