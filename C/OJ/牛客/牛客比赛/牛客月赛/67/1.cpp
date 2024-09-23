#include <bits/stdc++.h>
using namespace std;
int m[20];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        m[i] = 1;
    }
    for (int i = 0; i < 18; i++)
    {
        if (i % 6 == 0 && i != 0)
            cout << "\n";
        cout << m[i];
    }
    return 0;
}