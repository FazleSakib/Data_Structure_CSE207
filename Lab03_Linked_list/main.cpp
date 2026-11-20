#include <iostream>
#include "LinkedList.h"
int main()
{
    LinkedList *list = new LinkedList();
    cout << "     inserting First    -> ";
    list->insertFirst();
    list->insertFirst();
    list->insertFirst();
    list->insertFirst();
    list->printList();
    cout << "     inserting Last    ->";
    list->insertLast();
    list->insertLast();
    list->insertLast();
    list->insertLast();
    list->printList();
    cout << "     inserting Mid     ->";
    list->insertMid(3);
    list->printList();
    cout << "     delete first      ";
    list->deleteFirst();
    list->printList();
    cout << "     delete last   ";
    list->deleteLast();
    list->printList();
    cout << "     delete middle  ";
    list->deleteMiddle(5);
    cout << "     Final LIST    ";
    list->printList();
}