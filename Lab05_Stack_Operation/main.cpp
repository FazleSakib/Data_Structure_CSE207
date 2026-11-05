#include <iostream>
#include "stack.h"
using namespace std;
int main(){
    stack s;
    cout<< "Push operation "<< endl;
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    cout<< "\n";
    s.peek();
    cout<< "\n";
    cout<< "After Push operation "<< endl;
    s.print();
    cout<< "\n";
    s.pop();
    cout<< "\n";
    s.peek();
    cout<< "\n";
    s.pop();
    cout<< "\n";
    s.peek();
    cout<< "\n";
    cout<< "Finally after stack operation "<< endl;
    s.print();


}
