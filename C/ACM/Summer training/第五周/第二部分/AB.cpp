#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int p[N], n, m, k;
int maxn = 0, o = 0;
int cnt = 0;
struct node
{
    int d1, d2;
    int x, y;
    int id;
} f[3 * N];
struct ANS
{
    int id;
    int x;
} ans[N];
struct node1
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        return s1.d1 < s2.d1;
    }
};
struct node2
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        return s1.d2 < s2.d2;
    }
};
struct ans1
{
    bool operator()(const ANS &s1, const ANS &s2)
        const
    {
        return s1.id < s2.id;
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
void kruskal1()
{
    sort(f + 1, f + m + 1, node1());
    for (int i = 1; i <= m; i++)
    {
        if (find(f[i].x) != find(f[i].y))
        {
            p[find(f[i].x)] = find(f[i].y);
            cnt++;
            maxn = max(maxn, f[i].d1);
            ans[o].id = f[i].id;
            ans[o++].x = 1;
            if (cnt == k)
            {
                return;
            }
        }
    }
    return;
}
void kruskal2()
{
    sort(f + 1, f + m + 1, node2());
    for (int i = 1; i <= m; i++)
    {
        if (find(f[i].x) != find(f[i].y))
        {
            p[find(f[i].x)] = find(f[i].y);
            cnt++;
            maxn = max(maxn, f[i].d2);
            ans[o].id = f[i].id;
            ans[o++].x = 2;
            if (cnt == n - 1)
            {
                return;
            }
        }
    }
}
inline void slove()
{
    cin >> n >> k >> m;
    m--;
    for (int i = 0; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> f[i].x >> f[i].y >> f[i].d1 >> f[i].d2;
        f[i].id = i;
    }
    kruskal1();
    kruskal2();
    cout << maxn << endl;
    sort(ans, ans + n - 1, ans1());
    for (int i = 0; i < n - 1; i++)
    {
        cout << ans[i].id << " " << ans[i].x << endl;
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