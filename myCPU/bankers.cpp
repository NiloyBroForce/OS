#include <iostream>

using namespace std;

int main()
{
    int n, m;

    cout << "Enter the number of Processes: ";
    cin >> n;

    cout << "Enter the number of Resources: ";
    cin >> m;

    int alloc[n][m];
    int max[n][m];
    int avail[m];

    // Reading Allocation Matrix
    cout << "Enter the Allocation Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> alloc[i][j];
        }
    }

    // Reading Max Matrix
    cout << "Enter the Max Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    // Reading Available Resources
    cout << "Enter the Available Matrix:\n";

    for (int i = 0; i < m; i++)
    {
        cin >> avail[i];
    }

    int finish[n]{};
    int safeSeq[n]{};
    int need[n][m]{};
    int work[m];

    // Work = Available
    for (int i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }

    // Calculate Need Matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Display Need Matrix
    cout << "\nThe Need Matrix is:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << need[i][j] << " ";
        }

        cout << endl;
    }

    // Safety Algorithm
    int ind = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;

                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    safeSeq[ind] = i;
                    ind++;

                    for (int j = 0; j < m; j++)
                    {
                        work[j] += alloc[i][j];
                    }

                    finish[i] = 1;
                }
            }
        }
    }

    // Check if safe sequence exists
    if (ind == n)
    {
        cout << "\nThe Safe Sequence is: ";

        for (int i = 0; i < n; i++)
        {
            cout << "P" << safeSeq[i];

                cout << " -> ";
        }

        cout << endl;
    }
    else
    {
        cout << "\nSystem is not in a safe state" << endl;
    }
}
/*
5
3

0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

3 3 2
*/