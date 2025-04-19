#ifndef TREE_H
#define TREE_H
typedef struct TreeNode
{
    int data;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
    int visited;
} Tree;
Tree *createTree(int *arr, int n);
void preorder(Tree *tree);
void inorder(Tree *tree);
void postorder(Tree *tree);
void levelorder(Tree *tree);
void preorderIterative(Tree *tree);
void inorderIterative(Tree *tree);
void postorderIterative(Tree *tree);
int countTreeNodes(Tree *tree);
int sumTreeNodes(Tree *tree);
int countTreeDeg1Nodes(Tree *tree);
int countTreeLeafNodes(Tree *tree);
int countTreeDeg2Nodes(Tree *tree);
int countTreeDeg2Or1Nodes(Tree *tree);
void playWithTree();
#endif
