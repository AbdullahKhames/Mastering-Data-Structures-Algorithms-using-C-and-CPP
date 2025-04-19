#ifndef TREE_H
#define TREE_H
#include <iostream>

using namespace std;

class TreeNode
{
public:
    TreeNode *leftChild;
    int data;
    TreeNode *rightChild;
};

class Tree{
    private:
        TreeNode* root;
    public:
        Tree() { root = nullptr; }
        ~Tree();
        void CreateTree();
        void Preorder(){ Preorder(root); }  // Passing Private Parameter
        void Preorder(TreeNode* p);
        void Postorder(){ Postorder(root); }  // Passing Private Parameter
        void Postorder(TreeNode* p);
        void Inorder(){ Inorder(root); }
        void Inorder(TreeNode* p);
        void Levelorder(){ Levelorder(root); }  // Passing Private Parameter
        void Levelorder(TreeNode* p);
        int Height(){ return Height(root); }  // Passing Private Parameter
        int Height(TreeNode* p);
        int count(){ return count(root); }  // Passing Private Parameter
        int count(TreeNode* p);
        int sum(){ return sum(root); }  // Passing Private Parameter
        int sum(TreeNode* p);
        TreeNode* getRoot(){ return root; }
    };

#endif
