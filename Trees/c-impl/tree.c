#include "main.h"

void preorder(Tree *root) {
    if (root)
    {
        printf("%d", root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
    
}

void inorder(Tree *root) {
    if (root)
    {
        inorder(root->leftChild);
        printf("%d", root->data);
        inorder(root->rightChild);
    }
    
}
void postorder(Tree *root) {
    if (root)
    {
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%d", root->data);
    }
    
}

void preorderIterative(Tree *root) {
    Stack st;
    createStack(&st, 20);
    Tree *temp = root;
    while (temp != NULL || !isEmptyStack(st))
    {
        if (temp != NULL) {
            printf("%d", temp->data);
            pushStack(&st, temp);
            temp = temp->leftChild;
        } else {
            temp = popStack(&st);
            temp = temp->rightChild;
        }
    }
}

void inorderIterative(Tree *root) {
    Stack st;
    createStack(&st, 20);
    Tree *temp = root;
    while (temp != NULL || !isEmptyStack(st))
    {
        if (temp != NULL) {
            pushStack(&st, temp);
            temp = temp->leftChild;
        } else {
            temp = popStack(&st);
            printf("%d", temp->data);
            temp = temp->rightChild;
        }
    }
}
void postorderIterative(Tree *root) {
    Stack st;
    createStack(&st, 20);
    Tree *temp = root;
    while (temp != NULL || !isEmptyStack(st))
    {
        if (temp != NULL) {
            pushStack(&st, temp);
            temp = temp->leftChild;
        } else {
            temp = popStack(&st);
            if (!temp->visited){
                pushStack(&st, temp);
                temp->visited = 1;
                temp = temp->rightChild;
            } else if (temp->visited == 1){
                printf("%d", temp->data);
                temp->visited = 0;
                temp = NULL;
            }
        }
    }
}


void levelorder(Tree *root) {
    Queue queue;
    Create(&queue, 100);
    Tree *temp = root;
    printf("%d ", temp->data);
    enqueue(&queue, temp);
    while (!isEmpty(queue))
    {
        temp = dequeue(&queue);
        if (temp->leftChild)
        {
            printf("%d ", temp->leftChild->data);
            enqueue(&queue, temp->leftChild);
        }
        if (temp->rightChild)
        {
            printf("%d ", temp->rightChild->data);
            enqueue(&queue, temp->rightChild);
        }
        
    }
    
    
}
Tree *createTree(int *arr, int n) {
    Tree *root = (Tree *)malloc(sizeof(Tree));
    Tree *p;
    Tree *temp;
    struct Queue q;
    int i = 0;
    Create(&q, 100);
    root->data = arr[i++];
    root->rightChild = NULL;
    root->leftChild = NULL;
    root->visited = 0;
    enqueue(&q, root);
    while (i < n && !isEmpty(q))
    {
        p = dequeue(&q);
        if (p == NULL)
        {
            break;
        }
        // for left child
        if (arr[i] != -1) {
            temp = (Tree *)malloc(sizeof(Tree));
            temp->data = arr[i];
            temp->rightChild = NULL;
            temp->leftChild = NULL;
            temp->visited = 0;
            p->leftChild = temp;
            enqueue(&q, temp);
        }
        i++;
        if (arr[i] != -1) {
            temp = (Tree *)malloc(sizeof(Tree));
            temp->data = arr[i];
            temp->rightChild = NULL;
            temp->leftChild = NULL;
            temp->visited = 0;
            p->rightChild = temp;
            enqueue(&q, temp);
        }
        i++;
    }    
    return root;
}


int countTreeNodes(Tree *tree) {
    int x, y;
    if (tree)
    {
        x = countTreeNodes(tree->leftChild);
        y = countTreeNodes(tree->rightChild);
        return x + y + 1;
    }
    return 0;
    
}

int countTreeLeafNodes(Tree *tree) {
    int x, y;
    if (tree)
    {
        x = countTreeLeafNodes(tree->leftChild);
        y = countTreeLeafNodes(tree->rightChild);
        if (tree->leftChild == NULL && tree->rightChild == NULL)
        {
            return x + y + 1;
        } else {
            return x + y;
        }

    }
    return 0;
}

int countTreeDeg2Nodes(Tree *tree) {
    int x, y;
    if (tree)
    {
        x = countTreeDeg2Nodes(tree->leftChild);
        y = countTreeDeg2Nodes(tree->rightChild);
        if (tree->leftChild != NULL && tree->rightChild != NULL)
        {
            return x + y + 1;
        } else {
            return x + y;
        }

    }
    return 0;
}

int countTreeDeg2Or1Nodes(Tree *tree) {
    int x, y;
    if (tree)
    {
        x = countTreeDeg2Or1Nodes(tree->leftChild);
        y = countTreeDeg2Or1Nodes(tree->rightChild);
        if (tree->leftChild != NULL || tree->rightChild != NULL)
        {
            return x + y + 1;
        } else {
            return x + y;
        }

    }
    return 0;
}

int countTreeDeg1Nodes(Tree *tree) {
    int x, y;
    if (tree)
    {
        x = countTreeDeg1Nodes(tree->leftChild);
        y = countTreeDeg1Nodes(tree->rightChild);
        if ((tree->leftChild == NULL && tree->rightChild != NULL) ||
                (tree->leftChild != NULL && tree->rightChild == NULL))
        {
            return x + y + 1;
        } else {
            return x + y;
        }

    }
    return 0;
}

int height(Tree *tree) {
    int x, y;
    if (tree)
    {
        x = height(tree->leftChild);
        y = height(tree->rightChild);
        if (x > y)
        {
            return x + 1;
        } else {
            return y + 1;
        }
    }
    return 0;
}

int sumTreeNodes(Tree *tree) {
    int x, y;
    if (tree)
    {
        x = sumTreeNodes(tree->leftChild);
        y = sumTreeNodes(tree->rightChild);
        return x + y + tree->data;
    }
    return 0;
}


void playWithTree() {
    int size = 9;
    int arr[] = {5, 8, 6, -1, 9, 3, -1, 4, 2};
    Tree *root = createTree(arr, size);
    printf("\npre order traversal \n");
    preorder(root);
    printf("\npre order iterative traversal \n");
    preorderIterative(root);
    printf("\nin order traversal \n");
    inorder(root);
    printf("\nin orderIterative traversal \n");
    inorderIterative(root);
    printf("\npost order traversal \n");
    postorder(root);

    printf("\npost orderIterative traversal \n");
    postorderIterative(root);

    printf("\n levelorder traversal \n");
    levelorder(root);

    int count =countTreeNodes(root);
    printf("\n number of nodes in a tree %d\n", count);

    int sum =sumTreeNodes(root);
    printf("\n sum of nodes values in a tree %d\n", sum);
}
