#include<iostream>
using namespace std;
#define LENGTH 4

class CircularQueue{
    private:
    int rear = 0;
    int front =0;
    int count = 0;
    int queue[LENGTH] = {0};
    public:
    void enqueue(){
        if(count == LENGTH){
            cout<< " THE QUEUE IS FULL ! "<< endl;
        }
        else{
            int data;
            cout<< " ENTER THE DATA "<< endl;
            cin>>  data;
            queue[ rear ] = data;
            rear = (rear+1)% LENGTH;
            count++;
        }

    }
    void dequeue(){
        if(count == 0){
            cout<< " The queue is empty     "<< endl;
        }
        else{
            int item = queue[front];
            front = (front +1 )% LENGTH;
            count--;
            cout<< " The data "<< item << " is removed from the Queue"<< endl;
        }

    }
    void print(){
        if(count == 0){
            cout<< " The queue is empty     "<< endl;
        }
        else{
            cout<< " The Queue is -> "<< endl;
            for(int i = front ; i<(count + front); i++){
                cout<< queue[i% LENGTH] << endl;
            }
        }
    }

};
