#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, x;
    cin >> n >> x;
    int a[100100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    if (a[0] > x)
    {
        a[0] -= x;
        sum += a[0];
        a[0] = x;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] + a[i - 1] > x)
        {
            sum += a[i - 1] + a[i] - x;
            a[i] = x - a[i - 1];
        }
    }
    cout << sum << endl;
    return 0;
}