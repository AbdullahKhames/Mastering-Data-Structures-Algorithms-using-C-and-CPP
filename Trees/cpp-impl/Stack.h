#ifndef STACK_H
#define STACK_H
#include "tree.h"

class Stack
{
public:
    int size;
    int top;
    TreeNode **S;
    Stack(int size);
    ~Stack();
    void DisplayStack();
    void pushStack(TreeNode *x);
    TreeNode *popStack();
    TreeNode *peekStack(int index);
    int isEmptyStack();
    int isFullStack();
};

#endif
