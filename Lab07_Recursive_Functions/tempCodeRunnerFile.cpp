#include <iostream>
#include "Function.h"
using namespace std;
int main()
{
    Function f;
    cout << "FACTORIAL " << endl;
    cout << "Factorial of 5 ->     " << f.factorial(5) << endl;
    cout << "Factorial of 4  ->     " << f.factorial(4) << endl;
    cout << "Factorial of 3  ->     " << f.factorial(3) << endl;

    cout << "Fibonacci " << endl;
    cout << "Fibonacci of 5 ->     " << f.fibonacci(5) << endl;
    cout << "Fibonacci of 4  ->     " << f.fibonacci(4) << endl;
    cout << "Fibonacci of 3  ->     " << f.fibonacci(3) << endl;

    cout << "reverse print " << endl;
    f.reverse(100);

    cout << "JAVA print " << endl;
    f.times(100);

    cout << "palindrome  " << endl;
    cout << f.palindrome("abba")<< endl;
    cout << f.palindrome("elile")<< endl;
    cout << f.palindrome("azazj")<< endl;
}