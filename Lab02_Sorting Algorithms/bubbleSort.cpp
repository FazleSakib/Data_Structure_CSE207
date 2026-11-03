#include <iostream>
using namespace std;
int main()
{
    int data[6] = {110, 88, 60, 42, 102, 6};
    int size = 6;

    cout << "Before sorting \t";
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << "\t";
    }
    cout << "\n";
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            int temp;
            if (data[j + 1] < data[j])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    cout << "after sorting  \t";
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << "\t";
    }
    return 0;
}