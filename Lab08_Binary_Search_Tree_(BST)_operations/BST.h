#include <iostream>
#include "Node.h"
using namespace std;

class BST
{
public:
    Node *root;
    // no argument constructor
    BST()
    {
        root = nullptr;
    }

    // Creating Node
    Node *getNode(int item)
    {
        Node *newNode = new Node();
        newNode->data = item;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    // printing in pre-order, in-order, post-order and level-order with recursive algorithms.
    void preOrderTraversal(Node * temp){
        if (temp != nullptr)
        {
            cout << temp->data << " ";
            preOrderTraversal(temp->left);
            preOrderTraversal(temp->right);
        } 
    }
    
    void inOrderTraversal(Node *temp)
    {
        if (temp != nullptr)
        {
            inOrderTraversal(temp->left);
            cout << temp->data << " ";
            inOrderTraversal(temp->right);
        }
    }

    void postOrderTraversal(Node *temp)
    {
        if (temp != nullptr)
        {
            postOrderTraversal(temp->left);
            postOrderTraversal(temp->right);
            cout << temp->data << " ";
        }
    }

    // insert
    void insertHelper()
    {
        int item;
        cout << "Enter item to be inserted :     ";
        cin >> item;
        root = insertRecursive(root, item);
    }

    Node *insertRecursive(Node *temp, int item)
    {
        if (temp == nullptr)
        {
            temp = getNode(item);
            return temp;
        }
        else if (item < temp->data)
        {
            temp->left = insertRecursive(temp->left, item);
        }
        else
        {
            temp->right = insertRecursive(temp->right, item);
        }
        return temp;
    }

    // Minimum Value
    int minimum(Node *temp)
    {
        int minValue = temp->data;
        while (temp->left != nullptr)
        {
            temp = temp->left;
            minValue = temp->data;
        }
        return minValue;
    }

    // delete
    void deleteHelper()
    {
        int item;
        cout << "Enter  the data to be deleted :   ";
        cin >> item;
        root = deleteRecursive(root, item);
    }

    Node *deleteRecursive(Node *temp, int item)
    {
        if (temp == nullptr)
        {
            return nullptr;
        }
        else if (item < temp->data)
        {
            temp->left = deleteRecursive(temp->left, item);
        }
        else if (item > temp->data)
        {
            temp->right = deleteRecursive(temp->right, item);
        }
        else
        {

            // case:01 node with no Child
            if (temp->left == nullptr && temp->right == nullptr)
            {
                return nullptr;
            }

            // case:02 node with ONE child
            else if (temp->left == nullptr)
            {
                return temp->right;
            }
            else if (temp->right == nullptr)
            {
                return temp->left;
            }

            // case:03 node with both Child
            if (temp->left != nullptr && temp->right != nullptr)
            {
                int min = minimum(temp->right);
                temp->data = min;
                temp->right = deleteRecursive(temp->right, min);
            }
        }

        return temp;
    }

    // Search operation
    bool search(Node *root)
    {
        int item;
        cout << "Enter The item to be searched   :     ";
        cin >> item;

        return searchDataRecursive(root, item);
    }

    bool searchDataRecursive(Node* root, int item){
        if(root == nullptr){
            return false;
        }
        else if (item < root-> data){
            return searchDataRecursive(root->left, item);
        }
        else if(item> root->data){
            return searchDataRecursive(root->right, item);
        }
        else{
            return true;
        }
    }


};