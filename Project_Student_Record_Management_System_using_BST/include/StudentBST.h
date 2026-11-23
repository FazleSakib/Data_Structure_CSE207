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

            Node* node = findMin(temp->right);
            temp-> data = node->data;
            temp->right = deleteHelper(temp->right , temp->data.getRoll());
        }
        return temp;
    }

    void inorderHelper(Node* temp){
        if(temp == nullptr){
            return;
        }
        inorderHelper(temp->left);
        temp-> data.display();
            cout<< "\n";
        inorderHelper(temp->right);
    }

    public:

    StudentBST(){
        root = nullptr;
    }

    bool checkRecord(int roll){
        Node* temp = root;
        while(temp!= nullptr){
            if(roll == temp->data.getRoll()){
                return true;
            }
            else if( roll < temp->data.getRoll()){
                temp = temp->left;
            }
            else if(roll> temp->data.getRoll()){
                temp= temp->right;
            }
        }
        return false;
    }

    void createRecord(Student s){
        if(checkRecord(s.getRoll())){
            cout<<"Already account created.\n Failed to create Student Record";
            return;
        }

        root = insertHelper(root ,s);
        cout<< "Successfully Created Student Record of "<< s.getRoll()<< "\n";

    }

    void searchRecord(int roll){
        Node* temp = root;
        while(temp!= nullptr){
            if(roll == temp->data.getRoll()){
                cout<< "Student Record Found\n";
                temp->data.display();
                return;
            }
            else if(roll < temp->data.getRoll()){
                temp= temp-> left;
            }
            else{
                temp= temp-> right;
            }
        }
        cout<< "Student data"<< roll << "didnt found \n";
    }

    int deleteRecord(int roll){
        if(!checkRecord(roll)){
            return -1;
        }
        root = deleteHelper(root, roll);
        return 0;
    }

    void showRecord(){
        if(root == nullptr){
            cout<< "No student Record is available\n";
            return;
        }
        cout<< "Student Record :: \n";
        inorderHelper(root);
    }



};