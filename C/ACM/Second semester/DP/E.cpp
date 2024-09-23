#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int n, a[MAXN], dp[MAXN];

int LIS()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j <= i - 1; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << LIS() << endl;
    return 0;
}
