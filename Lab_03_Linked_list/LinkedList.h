#include<iostream>
#include "Node.h"
using namespace std;

class linkedList{
    public:
    Node* start;
    linkedList(){
        start = nullptr;
    }
    
    Node* getNode(){
    Node* newNode = new Node();
    cout<< "enter data: ";
    cin>> newNode-> data;
    newNode -> next = nullptr;
    newNode -> prev = nullptr;
    return newNode;
}

void insertFirst(){
    Node* newNode = getNode();
    if(start == nullptr){
        start = newNode;
    }
    else{
        newNode -> next = start;
        start = newNode;
    }
}

void printList(){
    
    Node* temp = start;
    while(temp -> next!= nullptr){
        cout<< temp-> data;
        temp = temp->next;
    }
}
};
