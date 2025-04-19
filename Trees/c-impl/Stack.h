#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct Stack
{
    int size;
    int top;
    Tree **S;
} Stack;

void createStack(struct Stack *st, int size);
void DisplayStack(struct Stack st);
void pushStack(struct Stack *st, Tree *x);
Tree *popStack(struct Stack *st);
Tree * peekStack(struct Stack st, int index);
int isEmptyStack(struct Stack st);
int isFullStack(struct Stack st);
