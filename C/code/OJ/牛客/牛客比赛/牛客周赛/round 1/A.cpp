#include <bits/stdc++.h>
using namespace std;
int main()

{
    int n;
    cin >> n;
    for (int i = 0; i < n * 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * n; j++)
        {
            cout << ".";
        }
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ".";
        }
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < (n - i - 1) * 2; j++)
        {
            cout << ".";
        }
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << ".";
        }
        cout << endl;
    }
    return 0;
}