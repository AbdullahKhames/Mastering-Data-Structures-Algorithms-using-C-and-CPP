#include "main.h"


Tree *createBstFromArray(int *arr, int n) {
    Tree *root = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        insertToBst(&root, arr[i]);
    }
    return root;
}

Tree *createBst(int rootVal) {
    Tree *root = NULL;
    insertToBst(&root, rootVal);
    return root;
}
void insertToBst(Tree **root, int val) {
    Tree *temp, *prev, *newNode;
    if (*root == NULL)
    {
        printf("root is null!\n");
        newNode = (Tree *) malloc(sizeof(Tree));
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->visited = 0;
        newNode->data = val;
        *root = newNode;
        return;
    }
    temp = *root;
    while (temp)
    {
        prev = temp;
        if (val == temp->data)
        {
            return;
        } else if (val < temp->data)
        {
            temp = temp->leftChild;
        } else 
        {
            temp = temp->rightChild;
        }
    }
    newNode = (Tree *) malloc(sizeof(Tree));
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->visited = 0;
    newNode->data = val;
    if (val < prev->data)
    {
        prev->leftChild = newNode;
    } else 
    {
        prev->rightChild = newNode;
    }
}

Tree *searchBST(Tree *root, int val) {
    Tree *temp;
    if (root == NULL)
    {
        printf("root is null!\n");
        return NULL;
    }
    temp = root;
    while (temp)
    {
        if (val == temp->data)
        {
            return temp;
        } else if (val < temp->data)
        {
            temp = temp->leftChild;
        } else 
        {
            temp = temp->rightChild;
        }
    }
}

Tree *searchBSTRecursivly(Tree *root, int key) {
    printf("searching in bst for key %d", key);
    if (root == NULL){
        return NULL;
    }
 
    if (key == root->data){
        return root;
    } else if (key < root->data){
        return searchBSTRecursivly(root->leftChild, key);
    } else {
        return searchBSTRecursivly(root->rightChild, key);
    }
}

Tree *insertToBstRecursive(Tree *root, int val) {
    Tree *newNode = NULL;
    if (!root)
    {
        newNode = (Tree *) malloc(sizeof(Tree));
        newNode->data = val;
        newNode->rightChild = newNode->leftChild = NULL;
        return newNode;
    }
    if (val < (root)->data)
    {
        (root)->leftChild = insertToBstRecursive((root)->leftChild, val);
    } else if (val >(root)->data) {
        (root)->rightChild = insertToBstRecursive((root)->rightChild, val);
    }
    return (root);
}

int Height(Tree *p) {
    int x;
    int y;
    if (p == NULL){
        return 0;
    }
    x = Height(p->leftChild);
    y = Height(p->rightChild);
    return x > y ? x + 1 : y + 1;
}
 
Tree* InPre(Tree *p) {
    while (p && p->rightChild != NULL){
        p = p->rightChild;
    }
    return p;
}
 
Tree* InSucc(Tree *p) {
    while (p && p->leftChild != NULL){
        p = p->leftChild;
    }
    return p;
}



Tree* Delete(Tree *root, int key) {
    Tree *q, *p;
    p = root;
    if (p == NULL){
        return NULL;
    }
 
    if (p->leftChild == NULL && p->rightChild == NULL){
        if (p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
 
    if (key < p->data){
        p->leftChild = Delete(p->leftChild, key);
    } else if (key > p->data){
        p->rightChild = Delete(p->rightChild, key);
    } else {
        if (Height(p->leftChild) > Height(p->rightChild)){
            q = InPre(p->leftChild);
            p->data = q->data;
            p->leftChild = Delete(p->leftChild, q->data);
        } else {
            q = InSucc(p->rightChild);
            p->data = q->data;
            p->rightChild = Delete(p->rightChild, q->data);
        }
    }
    return p;
}
 

void playWithBST() {
    int size = 9;
    int arr[] = {5, 8, 6, -1, 9, 3, -1, 4, 2};
    Tree *root = createBstFromArray(arr, size);



    int count =countTreeNodes(root);
    printf("\n number of nodes in a tree %d\n", count);

    int sum =sumTreeNodes(root);
    printf("\n sum of nodes values in a tree %d\n", sum);

    Tree *temp = searchBST(root, 50);
    printf("\n temp shouldn't be found %d \n", temp == NULL);

    
    insertToBst(&root, 50);
    temp = searchBST(root, 50);
    
    if (temp)
    {
        printf("\n temp should be found %d \n", temp->data);
    }

    Tree *temp2 = searchBST(root, 70);
    printf("\n temp2 shouldn't be found %d \n", temp2 == NULL);

    
    insertToBstRecursive(root, 70);
    temp2 = searchBST(root, 70);
    
    if (temp2)
    {
        printf("\n temp2 should be found %d \n", temp2->data);
    }
    printf("\nin order traversal \n");
    inorder(root);
    printf("\nin order traversal \n");


    int size2 = 5;
    int arr2[] = {50, 10, 40, 20, 30};
    Tree *root2 = createBstFromArray(arr2, size2);
    Delete(root2, 50);
    inorder(root2);
}
