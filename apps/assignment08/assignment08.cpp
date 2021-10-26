//
// File:   assignment08.cpp
// Author: Alex Willingham
// Purpose:
//
//
//
// C++ program to demonstrate BST
//
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

class BST
{
    int data;
    BST *left, *right;
    
public:
    
    BST();
    
    BST(int);
    
    BST* Insert(BST*, int);
    
    void Inorder(BST*);
};


BST ::BST()
: data(0)
, left(NULL)
, right(NULL)
{
}


BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        
        return new BST(value);
    }
    
    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    
    return root;
}

void BST ::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}


// Driver code
int main()
{
    clock_t start = clock();
    BST b, *root = NULL;
    srand(time(0));
    root = b.Insert(root, rand());
    b.Insert(root, rand());
    b.Insert(root, rand());
    b.Insert(root, rand());
    b.Insert(root, rand());
    b.Insert(root, rand());
    b.Insert(root, rand());
    
    b.Inorder(root);
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    
    return 0;
}
