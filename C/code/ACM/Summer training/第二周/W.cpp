#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 2e5 + 10;
int a[N], b[N];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++)
    {
        ans = __gcd(ans, a[i] - a[i - 1]);
    }
    for (int i = 1; i <= m; i++)
    {
        if (n == 1)
        {
            cout << a[1] + b[i] << " ";
        }
        else
        {
            cout << (__gcd(ans, a[1] + b[i])) << " ";
        }
    }
    return 0;
}