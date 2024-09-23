#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
int a[N], n, m;
struct node
{
    int l, r;
    int min;
} t[N << 2];
void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].min = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].min = std::min(t[p << 1].min, t[p << 1 | 1].min);
}
int query(int p, int l, int r)
{
    if (t[p].l >= l && t[p].r <= r)
        return t[p].min;
    int mid = (t[p].l + t[p].r) >> 1;
    int ans = 1e18;
    if (l <= mid)
        ans = std::min(ans, query(p << 1, l, r));
    if (r > mid)
        ans = std::min(ans, query(p << 1 | 1, l, r));
    return ans;
}
inline void slove()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    build(1, 1, n);
    while (m--)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << query(1, x, y) << " ";
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--)
        slove();
    return 0;
}