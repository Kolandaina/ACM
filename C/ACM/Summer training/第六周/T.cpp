#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int mod = 100003;
int n, m, x, y, tot = 0;
const int N = 2e6 + 10;
int head[N], to[N], nxt[N], d[N], ans[N];
bool p[N];
priority_queue<pair<int, int>> q;
void add(int x, int y)
{
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void disjkstra()
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = 1e9, p[i] = 0;
    }
    d[1] = 0;
    ans[1] = 1;
    q.push(make_pair(0, 1));
    while (q.size())
    {
        x = q.top().second;
        q.pop();
        if (p[x])
            continue;
        p[x] = 1;
        for (int i = head[x]; i; i = nxt[i])
        {
            y = to[i];
            if (d[y] > d[x] + 1)
            {
                d[y] = d[x] + 1;
                ans[y] = ans[x];
                q.push(make_pair(-d[y], y));
            }
            else if (d[y] == d[x] + 1)
            {
                ans[y] += ans[x];
                ans[y] %= mod;
            }
        }
    }
}
inline void slove()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    disjkstra();
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
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