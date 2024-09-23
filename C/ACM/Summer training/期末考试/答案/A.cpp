#include <bits/stdc++.h>

using namespace std;
#define int long long

int a[100005] = {};
int num[100005];
void solve()
{
    int n, m, sum = 0;
    cin >> n >> m;
    if (n < 1 || m < 1 || n > 1e5 || m > 1e5)
        cout << "@@@";
    for (int i = 0; i < n; ++i)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if (l > r || l < 1 || r > m)
            cout << "SS";
        if (x < 0 || x > 5000)
            cout << "@@";
        a[l] += x;
        a[r + 1] -= x;
        sum += x;
    }
    for (int i = 1; i <= m; ++i)
    {
        a[i] += a[i - 1];
        num[i] = a[i];
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        ans = max(ans, sum - num[i]);
    }
    cout << ans;
}

signed main()
{
    solve();
}