#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
void solve()
{
    int n, x;
    cin >> n >> x;
    if (n % x)
    {
        cout << "-1" << endl;
    }
    else
    {
        for (int i = 0; i <= n; i++)
        {
            a[i] = i;
        }
        a[1] = x, a[x] = n, a[n] = 1;
        int t = x;
        for (int i = 1; i * x < n; i++)
        {
            if (n % (i * x) == 0 && (x * i) % t == 0)
            {
                swap(a[i * x], a[t]);
                t = i * x;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}