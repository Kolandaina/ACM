#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 3e5 + 10, mod = 998244353;
int n, ans;
int x[210], l[210], dis[210];
vector<int> res;
bool check(int cnt)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = abs(x[i] - cnt);
    }
    sort(dis + 1, dis + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (l[i] < dis[i])
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> l[i];
    sort(l + 1, l + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            res.push_back(x[i] + l[j]);
            res.push_back(x[i] - l[j]);
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for (int i = 0; i < res.size() - 1; i++)
    {
        if (check(res[i] + 1)) ans += res[i + 1] - res[i] - 1;
    }
    for (int re : res)
    {
        if (check(re)) ans++;
    }
    cout << ans;
    return 0;
}
