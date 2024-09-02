#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> pre(n), nex(n);
    for (int i = 0; i < n; i++)
    {
        pre[i] = {a[0][i], i};
        nex[i] = {0, i};
    }
    sort(pre.begin(), pre.end());
    auto op = [&](int i, int j)
    {
        auto it = pre.begin();
        if (it->second == j)
        {
            it = next(it);
        }
        nex[j].first = a[i][j] + it->first;
    };
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            op(i, j);
        }
        pre = nex;
        sort(pre.begin(), pre.end());
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, nex[i].first);
    }
    cout << ans << endl;
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