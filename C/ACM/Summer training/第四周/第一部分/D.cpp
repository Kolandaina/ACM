#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
int b[N], c[N];
int dp[N];
int a[N];
int maxn = 1;
void init()
{
    for (int i = 0; i < 1010; i++)
    {
        a[i] = N;
    }
    1 [a] = 0;
    for (int i = 1; i <= 1010; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            a[i + i / j] = min(a[i + i / j], a[i] + 1);
            maxn = max(maxn, a[i + i / j]);
        }
    }
}
inline void slove()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        sum += c[i];
    }
    if (m >= maxn * n)
    {
        cout << sum << endl;
        return;
    }
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= a[b[i]]; j--)
        {
            dp[j] = max(dp[j - a[b[i]]] + c[i], dp[j]);
        }
    }
    cout << dp[m] << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    init();
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}