#include "bits/stdc++.h"

using namespace std;
const int mm = 2e3 + 50;
#define int long long
int dp[mm] = {};
int dp1[mm] = {};

void solve()
{
    int n;
    cin >> n;
    if (n > 2e3)
        cout << "@@@";
    int x1, x2;
    int id1 = 0, id2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        x1 = x2 = 1e18;
        for (int j = 1; j <= n; ++j)
        {
            int d;
            scanf("%lld", &d);
            if (id1 != j)
                dp[j] = dp1[id1] + d;
            else
                dp[j] = dp1[id2] + d;

            if (d > 1e6 || d < -1e6)
                cout << "@@@";
        }
        id1 = id2 = -1;
        for (int j = 1; j <= n; ++j)
        {
            if (dp[j] <= x1)
            {
                id2 = id1;
                x2 = x1;
                id1 = j;
                x1 = dp[j];
            }
            else if (dp[j] < x2)
            {
                id2 = j;
                x2 = dp[j];
            }
            dp1[j] = dp[j];
        }
    }
    int ans = 1e18;
    for (int i = 1; i <= n; ++i)
    {
        ans = min(ans, dp[i]);
    }
    cout << ans;
}

signed main()
{
    solve();
}