#include <bits/stdc++.h>
using namespace std;
#define int  long long
#define endl "\n"
const int N = 1e5 + 10;
int a[N], n, dp[N];
inline void slove()
{
    while (cin >> a[++n])
    {
    }
    n--;
    memset(dp, 0, sizeof(dp));
    dp[0] = INT_MAX;
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = temp + 1;
        while (r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if (dp[mid] >= a[i])
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        if (temp < l + 1)
        {
            temp = l + 1;
        }
        dp[l + 1] = a[i];
    }
    cout << temp << endl;
    temp = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = temp + 1;
        while (r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if (dp[mid] < a[i])
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        if (temp < l + 1)
        {
            temp = l + 1;
        }
        dp[l + 1] = a[i];
    }
    cout << temp << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) slove();
    return 0;
}