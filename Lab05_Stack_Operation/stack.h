#include <iostream>
using namespace std;
#define max 100
class stack
{
    int top;
    int arr[max];

public:
    stack()
    {
        // declare as empty
        top = -1;
    }
    void push(int num)
    {
        if (top >= max - 1)
        {
            cout << "   Stack Full" << endl;
        }
        else
        {
            cout << "Data wants to push     ";
            cin >> num;
            top++;
            arr[top] = num;
        }
    }
    void pop()
    {
        if (top < 0)
        {
            cout << " The stack is Empty    " << endl;
        }
        else
        {
            int rem = arr[top];
            top--;
            cout << rem << " is removed from the stack  " << endl;
        }
    }
    void peek()
    {
        if (top < 0)
        {
            cout << " The stack is Empty    " << endl;
        }
        else
        {
            int last = arr[top];
            cout<< last << "    is the last element of the stack    "<< endl;
        }
    }

    void print()
    {
        if(top < 0){
            cout<< " the stack is empty     "<< endl;
        }
        else{
            cout<< " the stack is -->"<< endl;
            for(int i = top; i>=0; i--){
                cout<< arr[i] << endl;
            }
        }
    }
};