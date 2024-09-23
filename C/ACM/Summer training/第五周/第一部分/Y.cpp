#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1010;
int p[N], n, m, t;
struct node
{
    double d;
    int x, y;
} f[N * N];
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
    sort(f + 1, f + t + 1, node1());
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= t; i++)
    {
        if (find(f[i].x) != find(f[i].y))
        {
            p[find(f[i].x)] = find(f[i].y);
            cnt++;
            sum += f[i].d;
            if (cnt == n)
            {
                return sum;
            }
        }
    }
    return 0;
}
inline void slove()
{
    cin >> m >> n;
    for (int i = 0; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (i < j && x != 0)
            {
                f[++t].x = i, f[t].y = j;
                f[t].d = x;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        f[++t].x = 0;
        f[t].y = i;
        f[t].d = m;
    }
    cout << kruskal() << endl;
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