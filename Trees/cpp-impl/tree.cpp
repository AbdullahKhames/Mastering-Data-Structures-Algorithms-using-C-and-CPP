#include "main.h"

     // scope resolution operator
    void Tree::CreateTree() {
        TreeNode *p, *temp;
        int x;
        Queue queue(25);
        Tree::root = new TreeNode;
        cout << "enter root node : " << endl;
        cin >> x;
        root->data = x;
        root->rightChild = nullptr;
        root->leftChild = nullptr;

        queue.enqueue(root);

        while (!queue.isEmpty()) {
            p = queue.dequeue();
            if (!p)
            {
                break;
            }
            cout << "enter value for left child of  "  << p->data << " node : " << endl;
            cin >> x;
            if (x != -1)
            {
                temp = new TreeNode;
                temp->data = x;
                temp->leftChild = nullptr;
                temp->rightChild = nullptr;
                p->leftChild = temp;
                queue.enqueue(temp);
            }
            
            cout << "enter value for right child of  "  << p->data << " node : " << endl;
            cin >> x;
            if (x != -1)
            {
                temp = new TreeNode;
                temp->data = x;
                temp->leftChild = nullptr;
                temp->rightChild = nullptr;
                p->rightChild = temp;
                queue.enqueue(temp);
            }
        }
    }
     
    void Tree::Preorder(TreeNode *p) {
        if (p)
        {
            cout << p->data;
            Preorder(p->leftChild);
            Preorder(p->rightChild);
        }
    }
     
    void Tree::Inorder(TreeNode *p) {
        if (p)
        {
            Inorder(p->leftChild);
            cout << p->data;
            Inorder(p->rightChild);
        }
        
    }
     
    void Tree::Postorder(TreeNode *p) {
        if (p)
        {
            Inorder(p->leftChild);
            Inorder(p->rightChild);
            cout << p->data;
        }
    }
     
    void Tree::Levelorder(TreeNode *p) {
        TreeNode *temp = p;
        if (!temp)
        {
            return;   
        }
        cout << temp->data << endl;
        Queue queue(20);
        queue.enqueue(temp);
        while (!queue.isEmpty())
        {
            temp = queue.dequeue();
            if (temp->leftChild)
            {
                printf("%d ", temp->leftChild->data);
                queue.enqueue(temp->leftChild);
            }
            if (temp->rightChild)
            {
                printf("%d ", temp->rightChild->data);
                queue.enqueue(temp->rightChild);
            }
            
        }
    }
     
    int Tree::Height(TreeNode *p) {
        TreeNode *temp = p;
        int x, y;
        if (!p)
        {
            return 0;
        }
        x =  Height(temp->leftChild);
        y =  Height(temp->rightChild);
        if (x > y)
        {
            return x + 1;
        } else {
            return y + 1;
        }        
    }
     
    Tree::~Tree() {
        // TODO
    }
    


    int Tree::count(TreeNode *root) {
        int x, y;
        if (root)
        {
            x = count(root->leftChild);
            y = count(root->rightChild);
            return x + y + 1;
        }
        return 0;
        
    }
    int Tree::sum(TreeNode *root) {
        int x, y;
        if (root)
        {
            x = sum(root->leftChild);
            y = sum(root->rightChild);
            return x + y + root->data;
        }
        return 0;
    }
