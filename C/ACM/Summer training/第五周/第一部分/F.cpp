#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
vector<vector<int>> g(N);
map<pair<int, int>, int> mp;
int n, l, r, nowl, nowr;
int val[N], typee[N];
int ans = 1;
bool vis[N];
void dfs(int t)
{
    for (auto e : g[t])
    {
        if (vis[e])
            continue;
        vis[e] = true;
        if (typee[t] == 1)
        {
            typee[e] = 2;
            val[e] = mp[{e, t}] - val[t];
            nowr = min(nowr, val[e] - l);
            nowl = max(nowl, val[e] - r);
        }
        else
        {
            typee[e] = 1;
            val[e] = mp[{e, t}] - val[t];
            nowr = min(nowr, r - val[e]);
            nowl = max(nowl, l - val[e]);
        }
        dfs(e);
    }
}
inline void slove()
{
    cin >> n >> l >> r;
    memset(vis, 0, sizeof(vis));
    memset(typee, 0, sizeof(typee));
    memset(val, 0, sizeof(val));
    for (int i = 0; i <= n; i++)
        g[i].clear();
    ans = 1;
    for (int i = 1; i < n; i++)
    {
        int op, x, y, w;
        cin >> op >> x >> y;
        if (op)
        {
            cin >> w;
            g[x].push_back(y);
            g[y].push_back(x);
            mp[{x, y}] = w, mp[{y, x}] = w;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        nowl = l, nowr = r;
        typee[i] = 1, val[i] = 0;
        dfs(i);
        if (nowl > nowr)
            ans = 0;
        else
            ans = ans * (nowr - nowl + 1) % mod;
    }
    cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}