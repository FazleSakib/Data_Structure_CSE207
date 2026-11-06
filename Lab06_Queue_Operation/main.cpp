#include <iostream>
#include "Linear_Queue.h"
#include "Circular_Queue.h"
using namespace std;

int main()
{
    cout << " Operation of Linear Queue " << endl;
    LinearQueue lq;
    lq.enqueue();
    lq.enqueue();
    lq.enqueue();
    lq.enqueue();
    lq.enqueue();
    lq.enqueue();
    lq.print();
    lq.dequeue();
    lq.dequeue();
    lq.print();

     cout << " Operation of Circular Queue " << endl;
    CircularQueue cq;
    cq.enqueue();
    cq.enqueue();
    cq.enqueue();
    cq.enqueue();
    cq.enqueue();
    cq.enqueue();
    cq.print();
    cq.dequeue();
    cq.dequeue();
    cq.print();
    cq.enqueue();
    cq.enqueue();
    cq.enqueue();
    cq.print();
}
