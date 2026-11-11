#include <iostream>
using namespace std;
class Function
{
public:
    // factorial of an integer number.
    int factorial(int num)
    {
        if (num == 0)
        {
            return 1;
        }
        else
        {
            return num * factorial(num - 1);
        }
    }

    // calculate the Fibonacci number, given the index value.
    int fibonacci(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else
        {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    // print the numbers 1 to 100 in reverse order.
    void reverse(int val)
    {
        if (val > 0)
        {
            cout << val << "\t";
            reverse(val - 1);
        }
    }

    // print the message “JAVA” 100 times

    void times(int n)
    {
        if (n > 0)
        {
            cout << "JAVA \t";
            times(n - 1);
        }
    }

    // calculate whether a given word is palindrome or not.

    bool palindrome(string word)
    {
        if (word.length() <= 1)
        {
            return true;
        }
        if (word.at(0) != word.at(word.length() - 1))
        {
            return false;
        }
        return palindrome(word.substr(1, word.length() - 2));
    }
};