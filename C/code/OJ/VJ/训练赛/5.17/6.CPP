#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 2e5 + 10;
int a[N], b[N], n, x;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[i] = i * (n - i + 1) * x;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, greater<int>());
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + (a[i] % mod) * (b[i] % mod) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}