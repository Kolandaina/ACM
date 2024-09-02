#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], dp[N];
void solve()
{
    int n;
    cin >> n;
    memset(dp, 0, N);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }
    int ans = 1;
    for (int i = n / 2; i > 0; i--)
    {
        for (int j = i; j <= n; j += i)
        {
            if (a[j] > a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(dp[i], ans);
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}