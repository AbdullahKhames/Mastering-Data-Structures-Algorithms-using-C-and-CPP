#ifndef BST_H
#define BST_H
#include "tree.h"

Tree *createBstFromArray(int *arr, int n);
Tree *createBst(int rootVal);
void insertToBst(Tree **root, int val);
Tree *searchBST(Tree *root, int val);
void playWithBST();
#endif
