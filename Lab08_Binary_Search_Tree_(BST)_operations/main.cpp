#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    BST *bst = new BST();
    int i = 1;
    while (i < 12)
    {
        bst->insertHelper();
        i++;
    }
    cout << "preOrderTraversal " << endl;
    bst->preOrderTraversal(bst->root);
    cout << "\ninOrderTraversal " << endl;
    bst->inOrderTraversal(bst->root);
    cout << "\npostOrderTraversal " << endl;
    bst->postOrderTraversal(bst->root);
    cout<<"\n";

    // Call search using -> and pass bst->root
    if (bst->search(bst->root))
    {
        cout << "Item found in the BST!" << endl;
    }
    else
    {
        cout << "Item NOT found in the BST!" << endl;
    }

    bst->deleteHelper();
    cout << endl
         << "After deleting     :  ";
    bst->inOrderTraversal(bst->root);
}