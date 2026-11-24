#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

class Node
{
public:
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

        else
        {
            // case01: only if right child left
            if (temp->left == nullptr)
            {
                Node *node = temp->right;
                delete temp;
                return node;
            }

            // case02: only if left child left
            else if (temp->right == nullptr)
            {
                Node *node = temp->left;
                delete temp;
                return node;
            }

            Node *node = findMin(temp->right);
            temp->data = node->data;
            temp->right = deleteHelper(temp->right, temp->data.getRoll());
        }
        return temp;
    }

    void inorderHelper(Node *temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        inorderHelper(temp->left);
        temp->data.display();
        cout << "\n";
        inorderHelper(temp->right);
    }

    void saveHelper(Node *temp, ofstream &file)
    {

        if (temp == nullptr)
        {
            return;
        }
        // inorder squence
        saveHelper(temp->left, file);
        file << temp->data.getRoll() << "," << temp->data.getName() << "," << temp->data.getCourse()
             << "," << temp->data.getTotalMarks() << "," << temp->data.getCgpa() << "\n";
        saveHelper(temp->right, file);
    }

public:
    StudentBST()
    {
        root = nullptr;
        loadFromCSV();
    }

    void saveToCSV(string filename = "data/students.csv")
    {
        // output file stream
        ofstream file("data/students.csv");
        if (!file)
        {
            return;
        }

        saveHelper(root, file);
        file.close();
    }

    void loadFromCSV()
    {
        // input file stream
        ifstream file("data/students.csv");
        if (!file)
        {
            return;
        }

        string rollStr, name, course, marksStr, cgpaStr;

        while (getline(file, rollStr, ','))
        {
            if (rollStr.empty() || rollStr == "\n")
                break;

            getline(file, name, ',');
            getline(file, course, ',');
            getline(file, marksStr, ',');
            getline(file, cgpaStr);

            int roll = stoi(rollStr);
            double marks = stod(marksStr);
            double cgpa = stod(cgpaStr);

            Student s(name, roll, course, marks, cgpa);
            root = insertHelper(root, s);
        }
        file.close();
    }

    bool checkRecord(int roll)
    {
        Node *temp = root;
        while (temp != nullptr)
        {
            if (roll == temp->data.getRoll())
            {
                return true;
            }
            else if (roll < temp->data.getRoll())
            {
                temp = temp->left;
            }
            else if (roll > temp->data.getRoll())
            {
                temp = temp->right;
            }
        }
        return false;
    }

    void createRecord(Student s)
    {
        if (checkRecord(s.getRoll()))
        {
            cout << "Already account created.\n Failed to create Student Record";
            return;
        }

        root = insertHelper(root, s);
        saveToCSV();
        cout << "Successfully Created Student Record of " << s.getRoll() << "\n";
    }

    void searchRecord(int roll)
    {
        Node *temp = root;
        while (temp != nullptr)
        {
            if (roll == temp->data.getRoll())
            {
                cout << "Student Record Found\n";
                temp->data.display();
                return;
            }
            else if (roll < temp->data.getRoll())
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        cout << "Student data" << roll << "didnt found \n";
    }

    int deleteRecord(int roll)
    {
        if (!checkRecord(roll))
        {
            return -1;
        }
        root = deleteHelper(root, roll);
        saveToCSV();
        return 0;
    }

    void showRecord()
    {
        if (root == nullptr)
        {
            cout << "No student Record is available\n";
            return;
        }
        cout << "Student Record :: \n";
        inorderHelper(root);
    }
};