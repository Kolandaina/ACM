#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
int p[N], n, m, t;
struct node
{
    double d;
    int x, y;
} f[N];
struct road
{
    int x, y;
} g[N];
struct node1
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        return s1.d < s2.d;
    }
};
int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
double kruskal()
{
    sort(f, f + t, node1());
    int cnt = 0;
    int ans = n - m;
    for (int i = 0; i < t; i++)
    {
        if (find(f[i].x) != find(f[i].y))
        {
            p[find(f[i].x)] = find(f[i].y);
            cnt++;
            if (cnt == ans)
            {
                return f[i].d;
            }
        }
    }
    return 0;
}
inline void slove()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i].x >> g[i].y;
    }
    for (int i = 0; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            f[t].d = sqrt(pow(g[i].x - g[j].x, 2) + pow(g[i].y - g[j].y, 2));
            f[t].x = i;
            f[t].y = j;
            t++;
        }
    }
    printf("%.2f", kruskal());
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