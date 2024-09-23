#include <bits/stdc++.h>
using namespace std;
int t, n, a[10010];
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int b = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b ^= a[i];
        }
        if (b == 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
