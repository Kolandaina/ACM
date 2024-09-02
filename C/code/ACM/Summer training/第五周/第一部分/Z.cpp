#include <bits/stdc++.h>
using namespace std;
#define int  long long
#define endl "\n"
const int N = 1010;
int p[N], n, m, k, t;
struct node
{
    double d;
    int x, y;
} f[N * N];
struct node1
{
    bool operator()(const node &s1, const node &s2) const
    {
        return s1.d < s2.d;
    }
};
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
double kruskal()
{
    sort(f + 1, f + m + 1, node1());
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        if (find(f[i].x) != find(f[i].y))
        {
            p[find(f[i].x)] = find(f[i].y);
            cnt++;
            sum += f[i].d;
            if (cnt == n - k) return sum;
        }
    }
    return 0;
}
inline void slove()
{
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) cin >> f[i].x >> f[i].y >> f[i].d;
    if (k > n)
    {
        cout << "No Answer" << endl;
        return;
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
    while (t--) slove();
    return 0;
}