#include "main.h"


Stack::Stack(int size)
{
    size = size;
    top = -1;
    S = (TreeNode **)malloc(size * sizeof(TreeNode *));
}
void Stack::DisplayStack()
{
    int i;
    for (i = top; i >= 0; i--)
        printf("%d ", S[i]);
    printf("\n");
}

void Stack::pushStack(TreeNode *x)
{
    if (top == size - 1)
        printf("Stack overflow\n");
    else
    {
        top++;
        S[top] = x;
    }
}

TreeNode * Stack::popStack()
{
    TreeNode * x = NULL;
    if (top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = S[top--];
    }
    return x;
}

TreeNode * Stack::peekStack(int index)
{
    TreeNode * x = NULL;
    if (top - index + 1 < 0)
        printf("Invalid Index \n");
    x = S[top - index + 1];
    return x;
}

int Stack::isEmptyStack()
{
    if (top == -1)
        return 1;
    return 0;
}

int Stack::isFullStack()
{
    return top == size - 1;
}
