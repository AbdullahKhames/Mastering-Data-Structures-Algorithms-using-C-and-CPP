#include "stack.h"


void createStack(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (Tree **)malloc(st->size * sizeof(Tree *));
}
void DisplayStack(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

void pushStack(struct Stack *st, Tree *x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

Tree *popStack(struct Stack *st)
{
    Tree * x = NULL;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

Tree * peekStack(struct Stack st, int index)
{
    Tree * x = NULL;
    if (st.top - index + 1 < 0)
        printf("Invalid Index \n");
    x = st.S[st.top - index + 1];
    return x;
}

int isEmptyStack(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int isFullStack(struct Stack st)
{
    return st.top == st.size - 1;
}
