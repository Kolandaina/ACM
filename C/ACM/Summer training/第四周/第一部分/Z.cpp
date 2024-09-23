#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
int dp[N];
signed main()
{
    int n;
    cin >> n;
    int maxn = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        maxn = max(maxn, x);
        a[x]++;
    }
    dp[0] = 0, dp[1] = a[1];
    for (int i = 2; i <= maxn; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i] * i);
    }
    cout << dp[maxn] << endl;
    return 0;
}