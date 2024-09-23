#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m = n / 2 + 1;
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << "  ";
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;
    for (int i = 0; i < m - 2; i++)
    {
        cout << "*";
        for (int j = 0; j < n - 2; j++)
        {
            cout << " ";
        }
        cout << "*  *";
        for (int j = 0; j < n - 2; j++)
        {
            cout << " ";
        }
        cout << "*" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << "  ";
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            cout << " ";
        }
        cout << "*" << endl;
    }
    return 0;
}