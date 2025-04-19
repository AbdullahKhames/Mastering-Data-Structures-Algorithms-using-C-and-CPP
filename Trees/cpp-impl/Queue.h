#ifndef QUEUE_H
#define QUEUE_H
#include "tree.h"

 

 
class Queue{
private:
    int size;
    int front;
    int rear;
    TreeNode** Q;
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(TreeNode* x);
    TreeNode* dequeue();
};
 
#endif
