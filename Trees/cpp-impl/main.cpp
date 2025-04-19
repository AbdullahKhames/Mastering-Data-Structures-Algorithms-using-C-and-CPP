#include "main.h"

int main()
{
    Tree t;
 
    t.CreateTree();
 
    // cout << "Preorder: " << flush;
    // t.Preorder(t.getRoot());
    // cout << endl;
 
    // cout << "Inorder: " << flush;
    // t.Inorder(t.getRoot());
    // cout << endl;
 
    // cout << "Postorder: " << flush;
    // t.Postorder(t.getRoot());
    // cout << endl;
 
    // cout << "Levelorder: " << flush;
    // t.Levelorder(t.getRoot());
    // cout << endl;
 
    // cout << "Height: " << t.Height(t.getRoot()) << endl;
 
    cout << "Recursive Passing Private Parameter in Constructor" << endl;
 
    cout << "Preorder: " << flush;
    t.Preorder();
    cout << endl;
 
    cout << "Inorder: " << flush;
    t.Inorder();
    cout << endl;
 
    cout << "Postorder: " << flush;
    t.Postorder();
    cout << endl;
 
    cout << "Levelorder: " << flush;
    t.Levelorder();
    cout << endl;
 
    cout << "Height: " << t.Height() << endl;
    cout << "count: " << t.count() << endl;
    cout << "sum: " << t.sum() << endl;
    return (0);
}
