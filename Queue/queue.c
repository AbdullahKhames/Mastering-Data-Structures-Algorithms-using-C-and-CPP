#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int size;
    int head;
    int tail;
    int *arr;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    queue->arr = (int *) malloc(sizeof(int) * k);
    queue->size = k;
    queue->tail = -1;
    queue->head = -1;
    return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* queue) {
    if ((queue->tail == -1) && (queue->head == -1)) {
        return true;
    }
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* queue) {
    if (queue->tail == queue->head == -1) {
        return false;
    }
    if (queue->head == 0 && queue->tail == queue->size - 1) {
        return true;
    } else if (queue->head - queue->tail == 1) {
        return true;
    }
    return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* queue, int value) {

    if (!myCircularQueueIsFull(queue)) {
        if (myCircularQueueIsEmpty(queue)) {
            queue->head++;
        }
        queue->tail++;
        if (queue->tail >= queue->size) {
            queue->tail = 0;
        }
        // how to handle case when tail is less that head then it suddenly became more?!
        queue->arr[queue->tail] = value;
        return true;
    }
    return false;

}

bool myCircularQueueDeQueue(MyCircularQueue* queue) {
    if (myCircularQueueIsEmpty(queue)) {
        return false;
    }
    queue->arr[queue->head] = 0;
    if (queue->head == queue->tail) {
        queue->tail = queue->head = -1;
        return true;
    }
    queue->head++;
    if (queue->head >= queue->size) {
        queue->head = 0;
        return true;
    }

    return true;
}


int myCircularQueueFront(MyCircularQueue* queue) {
    if (myCircularQueueIsEmpty(queue)) {
        return -1;
    }
    return queue->arr[queue->head];
}


int myCircularQueueRear(MyCircularQueue* queue) {
    if (myCircularQueueIsEmpty(queue)) {
        return -1;
    }
    return queue->arr[queue->tail];
}

void myCircularQueuePrint(MyCircularQueue* queue) {
    printf("start print the queue\n");
    printf("internal pointers current locations for head %d for tail %d\n", queue->head, queue->tail);
    for (int i = 0; i < queue->size; i++)
    {
        printf("element at index %d is %d \n", i, queue->arr[i]);
    }
    printf("finish print the queue\n");
}

void myCircularQueueFree(MyCircularQueue* queue) {
    free(queue->arr);
    free(queue);
}

float calculateMovingAverage(MyCircularQueue* queue, int window) {
    int tailElements = 0, diff, sum = 0, count = 0;
    if (myCircularQueueIsEmpty(queue) || window > queue->size) {
        return -1;
    }
    if (window == queue->size)
    {
        for (int i = 0; i < queue->size; i++)
        {
            //because in deque i make the element equal zero so i can add any elemnt!
            sum += queue->arr[i];
        }
        
    } else {
        diff = queue->tail - window + 1;
        if (diff >= 0) {
            for (int i = queue->tail; i >= diff; i--)
            {
                sum += queue->arr[i];
                count++;
            }
        } else {
            for (int i = queue->tail; i >= 0; i--)
            {
                sum += queue->arr[i];
                tailElements++;
                count++;
            }
            diff = window - tailElements;
            for (int i = queue->size - 1; i > queue->size - 1 - diff && queue->arr[i] != 0; i--)
            {
                sum += queue->arr[i];
                count++;
            } 
        }
    }
    printf("sum is equal to %d, count is equal to %d\n", sum, count);
    return (float) sum / count;
}
void test1() {
    int val, size = 3;
    bool isExist;
    MyCircularQueue* obj = myCircularQueueCreate(size);
    myCircularQueuePrint(obj);
    isExist = myCircularQueueIsEmpty(obj);
    printf("is it empty ? %d\n", isExist);
    isExist = myCircularQueueEnQueue(obj, 1);
    printf("enque 1 ? %d\n", isExist);
    isExist = myCircularQueueEnQueue(obj, 2);
    printf("enque 2 ? %d\n", isExist);
    isExist = myCircularQueueEnQueue(obj, 3);
    printf("enque 3 ? %d\n", isExist);
    myCircularQueuePrint(obj);
    isExist = myCircularQueueEnQueue(obj, 4);
    printf("enque 4 ? %d\n", isExist);
    val = myCircularQueueRear(obj);
    myCircularQueuePrint(obj);
    printf("rear value -> %d\n", val);
    isExist = myCircularQueueIsFull(obj);
    printf("is it full ? %d\n", isExist);
    isExist = myCircularQueueDeQueue(obj);
    printf("deque ? %d\n", isExist);
    myCircularQueuePrint(obj);
    isExist = myCircularQueueEnQueue(obj, 4);
    printf("enqueue 4 ? %d\n", isExist);
    isExist = myCircularQueueIsFull(obj);
    printf("is it full ? %d\n", isExist);
    val = myCircularQueueRear(obj);
    printf("rear %d -> \n", val);
    myCircularQueuePrint(obj);
    
    myCircularQueueFree(obj);

}

void test2() {
    int val, size = 6;
    bool isExist;
    MyCircularQueue* obj = myCircularQueueCreate(size);
    isExist = myCircularQueueEnQueue(obj, 6);
    printf("enque 6 ? %d\n", isExist);
    val = myCircularQueueRear(obj);
    printf("rear value -> %d\n", val);
    val = myCircularQueueRear(obj);
    printf("rear value -> %d\n", val);
    isExist = myCircularQueueDeQueue(obj);
    printf("deque ?  %d\n", isExist);
    isExist = myCircularQueueEnQueue(obj, 5);
    printf("enque 5 ? %d\n", isExist);
    val = myCircularQueueRear(obj);
    printf("rear value -> %d\n", val);
    isExist = myCircularQueueDeQueue(obj);
    printf("deque ? %d\n", isExist);
    val = myCircularQueueFront(obj);
    printf("rear value -> %d\n", val);
    isExist = myCircularQueueDeQueue(obj);
    printf("deque ? %d\n", isExist);
    isExist = myCircularQueueDeQueue(obj);
    printf("deque ? %d\n", isExist);
    isExist = myCircularQueueDeQueue(obj);
    printf("deque ? %d\n", isExist);
    myCircularQueuePrint(obj);
    myCircularQueueFree(obj);

}

void test3() {
    float val, size = 4;
    bool isExist;
    MyCircularQueue* obj = myCircularQueueCreate(size);
    isExist = myCircularQueueEnQueue(obj, 1);
    val = calculateMovingAverage(obj, 3);
    printf("calculateMovingAverage for window 3 -> %f\n", val);
    isExist = myCircularQueueEnQueue(obj, 10);
    val = calculateMovingAverage(obj, 3);
    printf("calculateMovingAverage for window 3 -> %f\n", val);
    isExist = myCircularQueueEnQueue(obj, 3);
    val = calculateMovingAverage(obj, 3);
    printf("calculateMovingAverage for window 3 -> %f\n", val);
    isExist = myCircularQueueEnQueue(obj, 5);
    val = calculateMovingAverage(obj, 3);
    printf("calculateMovingAverage for window 3 -> %f\n", val);
    myCircularQueuePrint(obj);
    myCircularQueueFree(obj);

}
int main () {
    test3();
    return 0;
}
