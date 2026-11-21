#include <iostream>
#include "Student.h"
using namespace std;

struct Node
{
    Student data;
    Node *left;
    Node *right;

    Node(Student s)
    {
        data = s;
        left = nullptr;
        right = nullptr;
    }
};

class StudentBST
{
private:
    Node *root;

public:
    // recursive helper to sort by roll
    Node *insertHelper(Node *temp, Student s)
    {
        if (temp == nullptr)
        {
            return new Node(s);
        }

        if (s.getRoll() < temp->data.getRoll())
        {
            temp->left = insertHelper(temp->left, s);
        }
        else if (s.getRoll() > temp->data.getRoll())
        {
            temp->right = insertHelper(temp->right, s);
        }

        return temp;
    }

    Node *findMin(Node *temp)
    {
        while (temp != nullptr && temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node *deleteHelper(Node *temp, int roll)
    {
        if (temp == nullptr)
        {
            return nullptr;
        }

        if (roll < temp->data.getRoll())
        {
            temp->left = deleteHelper(temp->left, roll);
        }

        else if (roll > temp->data.getRoll())
        {
            temp->right = deleteHelper(temp->right, roll);
        }

        else{
            //case01: only if right child left
            if(temp->left ==nullptr){
                Node* node = temp->right;
                delete temp;
                return node;
            }

            //case02: only if left child left
            else if (temp->right == nullptr){
                Node* node = temp-> left;
                delete temp;
                return node;
            }

            Node* node = findMin(node->right);
            temp-> data = node->data;
            node->right = deleteHelper(node->right , temp->data.getRoll());
        }
    }
};