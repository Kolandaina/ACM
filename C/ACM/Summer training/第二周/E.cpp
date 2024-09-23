#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1010;
int dp[N], a[N], t[N];
signed main()
{
    int n, m;
    cin >> n >> m;
    if (n >= m)
    {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= m;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            t[j] = dp[j];
        }
        for (int j = 0; j < m; j++)
        {
            if (dp[j] >= 1 && t[j] != 0)
            {
                dp[(j + a[i]) % m]++;
            }
        }
    }
    if (dp[0] > 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
