#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList
{
public:
    Node *start;
    LinkedList()
    {
        start = nullptr;
    }

    Node *getNode()
    {
        Node *newNode = new Node();
        cout << "enter data: ";
        cin >> newNode->data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

    void insertFirst()
    {
        Node *newNode = getNode();
        if (start == nullptr)
        {
            start = newNode;
        }
        else
        {
            newNode->next = start;
            start->prev = newNode;
            start = newNode;
        }
    }

    void insertLast()
    {
        Node *newNode = getNode();
        Node *temp = start;
        if (start == nullptr)
        {
            start = newNode;
            return;
        }
        else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertMid(int pos)
    {
        Node *newNode = getNode();

        cout << "    Enter the position  ";
        cin >> pos;
        if (pos > 1 && pos < nodeCounter())
        {
            Node *temp = start;
            int ctr = 1;
            while (ctr < pos - 1)
            {
                temp = temp->next;
                ctr++;
            }

            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }

        else
        {
            cout << "InCorrect position entered";
        }
    }

    void deleteFirst()
    {
        if (start == nullptr)
        {
            cout << " Empty data ";
        }
        else
        {
            start = start->next;
        }
    }

    void deleteLast()
    {
        if (start == nullptr)
        {
            cout << " Empty data ";
        }
        else
        {
            Node *temp = start;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->prev->next = nullptr;
        }
    }

    void deleteMiddle(int pos)
    {
        Node *temp = start;
        cout << "    Enter the position  ";
        cin >> pos;
        if (pos > 1 && pos < nodeCounter())
        {
            int ctr = 1;
            while (ctr != pos)
            {
                temp = temp->next;
                ctr++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;
        }
        else
        {
            cout << "InCorrect position entered";
        }
    }

    int nodeCounter()
    {
        int count = 0;
        Node *temp = start;
        while (temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    void printList()
    {

        Node *temp = start;
        while (temp != nullptr)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }
};
