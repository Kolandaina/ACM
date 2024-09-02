#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 11;
vector<vector<int>> g(N);
vector<int> deep(N);
int n, d;
inline void bfs()
{
    queue<int> q;
    q.push(1);
    deep[1] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto e : g[t])
        {
            if (deep[e])
                continue;
            deep[e] = deep[t] + 1;
            q.push(e);
        }
    }
}
inline void slove()
{
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs();
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (deep[i] <= d)
            ans++;
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