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

class StudentBST{
    private:
    Node* root;

    public:
    //recursive helper to sort by roll
    Node* insertHelper(Node* temp, Student s){
        if(temp == nullptr){
            return new Node(s);
        }

         if(s.getRoll() < temp-> data.getRoll()){
            temp->left= insertHelper(temp->left, s);
        }
        else if(s.getRoll() > temp-> data.getRoll()){
            temp-> right = insertHelper(temp->right, s);
        }

        return temp;
    }

   



};