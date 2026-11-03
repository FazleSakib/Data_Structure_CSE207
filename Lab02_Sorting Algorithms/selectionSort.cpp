#include <iostream>
using namespace std;
int main()
{
    int i, j, temp, minIndex, size = 6;
    int data[6] = {17, 19, 6, 4, 23, 11};
    cout << "Before sorting \t";
    for (i = 0; i < size; i++)
    {
        cout << data[i] << "\t";
    }
    cout << "\n";
    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++)
        {
            if (data[j] < data[minIndex])
            {
                minIndex = j;
            }
        }
        temp = data[minIndex];
        data[minIndex] = data[i];
        data[i] = temp;
    }
    cout << "After sorting \t";
    for (i = 0; i < size; i++)
    {
        cout << data[i] << "\t";
    }
    return 0;
}