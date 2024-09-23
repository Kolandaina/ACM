#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
vector<vector<int>> g(N);
vector<int> bfs(int s, int n)
{
    queue<int> q;
    vector<int> d(n + 1, -1);
    q.push(s);
    d[s] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto e : g[t])
        {
            if (d[e] == -1)
            {
                d[e] = d[t] + 1;
                q.push(e);
            }
        }
    }
    return d;
}
inline void slove()
{
    int n, k, c;
    cin >> n >> k >> c;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> deep1 = bfs(1, n);
    int res = max_element(deep1.begin(), deep1.end()) - deep1.begin();
    vector<int> deep2 = bfs(res, n);
    int res2 = max_element(deep2.begin(), deep2.end()) - deep2.begin();
    vector<int> deep3 = bfs(res2, n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, k * max(deep2[i], deep3[i]) - c * deep1[i]);
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