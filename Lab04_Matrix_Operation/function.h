#include <stdio.h>
#include <iostream>
using namespace std;
class function
{
public:
    int r1, r2, c1, c2, i, j, k;
    int dataA[100][100], dataB[100][100], dataC[100][100];

    void matA()
    {
        // input
        cout << " Give the col and row number for matA " << endl;
        cin >> r1 >> c1;
        cout << "    MatA input  " << endl;
        for (i = 1; i <= r1; i++)
        {
            for (j = 1; j <= c1; j++)
            {
                cin >> dataA[i][j];
            }
        }
        // output
        cout << "    MatA output  " << endl;
        for (i = 1; i <= r1; i++)
        {
            for (j = 1; j <= c1; j++)
            {
                cout << dataA[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void matB()
    {
        // input
        cout << " Give the col and row number for matB " << endl;
        cin >> r2 >> c2;
        cout << "    MatB input  " << endl;
        for (i = 1; i <= r2; i++)
        {
            for (j = 1; j <= c2; j++)
            {
                cin >> dataB[i][j];
            }
        }
        // output
        cout << "    MatB output  " << endl;
        for (i = 1; i <= r2; i++)
        {
            for (j = 1; j <= c2; j++)
            {
                cout << dataB[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void addition()
    {
        if (r1 == r2 && c1 == c2)
        {
            cout << " The matrix addition id valid" << endl;
            // input
            for (i = 1; i <= r2; i++)
            {
                for (j = 1; j <= c2; j++)
                {
                    dataC[i][j] = dataA[i][j] + dataB[i][j];
                }
            }
            // output
            for (i = 1; i <= r2; i++)
            {
                for (j = 1; j <= c2; j++)
                {
                    cout << dataC[i][j] << "     ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Given matrix are invalid for addition " << endl;
        }
    }
    void substitution()
    {

        if (r1 == r2 && c1 == c2)
        {
            cout << " The matrix substitution is valid" << endl;
            // input
            for (i = 1; i <= r2; i++)
            {
                for (j = 1; j <= c2; j++)
                {
                    dataC[i][j] = dataA[i][j] - dataB[i][j];
                }
            }
            // output
            for (i = 1; i <= r2; i++)
            {
                for (j = 1; j <= c2; j++)
                {
                    cout << dataC[i][j] << "     ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Given matrix are invalid for substitution " << endl;
        }
    }

    void transposeA()
    {
        // output
        cout << "    MatA transpose output  " << endl;
        for (i = 1; i <= r1; i++)
        {
            for (j = 1; j <= c1; j++)
            {
                cout << dataA[j][i] << "  ";
            }
            cout << endl;
        }
    }

    void transposeB()
    {
        // output
        cout << "    MatB transpose output  " << endl;
        for (i = 1; i <= r2; i++)
        {
            for (j = 1; j <= c2; j++)
            {
                cout << dataB[j][i] << "  ";
            }
            cout << endl;
        }
    }
    void multiplication()
    {
        if (c1 == r2)
        {
            cout << " The matrix multiplication is valid" << endl;
            for (i = 1; i <= r1; i++)
            {
                for (j = 1; j <= c2; j++)
                {
                    dataC[i][j] = 0;
                    for (k = 1; k <= c1; k++)
                    {
                        dataC[i][j] += dataA[i][k] * dataB[k][j];
                    }
                }
            }

            // output
            for (i = 1; i <= r1; i++)
            {
                for (j = 1; j <= c2; j++)
                {
                    cout << dataC[i][j] << "     ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Given matrix are invalid for multiplication " << endl;
        }
    }
};