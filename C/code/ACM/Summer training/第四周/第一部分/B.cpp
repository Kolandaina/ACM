#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e7 + 10;
int w[N], v[N];
int dp[N];
inline void slove()
{
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = w[i]; j <= t; j++)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[t] << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}