#include <iostream>
using namespace std;
#define SIZE 100
class LinearQueue
{
private:
    int rear = 0;
    int front = 0;
    int queue[SIZE] = {0};

public:
    void enqueue()
    {
        if (rear == SIZE)
        {
            cout << " The array is full cant enqueue " << endl;
        }
        else
        {
            int val;
            cout << " Give the value  " << endl;
            cin >> val;
            queue[rear] = val;
            rear = rear + 1;
        }
    }

    void dequeue()
    {
        if (front == rear)
        {
            cout << " The array is empty cant dequeue " << endl;
        }
        else
        {
            int item = queue[front];
            front = front + 1;
            cout<< " The data    " << item << "    is removed from the queue."<< endl;
        }
    }

    void print(){
        if(front == rear){
            cout << " The Queue is Empty ";
        }
        else{
            cout<< " Printing the queue ->"<< endl;
            for(int i = rear-1; i>= front ; i--){
                cout<< queue[i] << endl;
            }
        }
    }
};