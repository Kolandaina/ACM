#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
            cout << "pb wins" << endl;
        else
            cout << "zs wins" << endl;
    }
    return 0;
}