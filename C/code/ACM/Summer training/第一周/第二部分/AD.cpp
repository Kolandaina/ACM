#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int cnt(int x)
{
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (mid * mid > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
    }
    int ans = (l - 1) * 3;
    if (x >= l * l + l && x < l * l + 2 * l)
        ans++;
    if (x == l * l + l * 2)
        ans += 2;
    return ans + 1;
}
void slove()
{
    cin >> n >> m;
    cout << abs(cnt(n - 1) - cnt(m)) << endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}