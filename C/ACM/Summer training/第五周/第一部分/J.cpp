#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
vector<vector<int>> g(N);
int n;
int a[N], deep[N], father[N];
int id[N], b[N];
inline void bfs()
{
    std::queue<int> q;
    q.push(1);
    deep[1] = 1;
    father[1] = 0;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (auto e : g[t])
        {
            if (deep[e])
                continue;
            father[e] = t;
            deep[e] = deep[t] + 1;
            q.push(e);
        }
    }
}
inline void slove()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    bfs();
    for (int i = 2; i <= n; i++)
    {
        if (deep[a[i]] < deep[a[i - 1]])
        {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        id[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = father[a[i]];
    }
    int len = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= len; i++)
    {
        if (id[b[i]] < id[b[i - 1]])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout
        << "Yes" << endl;
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