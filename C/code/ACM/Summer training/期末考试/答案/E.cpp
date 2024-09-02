#include <bits/stdc++.h>

using namespace std;
int a[10002];
int main()
{

    long long m, n;
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        long long op;
        cin >> op;
        long long x = sqrt(op);
        if (op == x * x)
        {
            cout << "T" << endl;
        }
        else
            cout << "F" << endl;
    }
}