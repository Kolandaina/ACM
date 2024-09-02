#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct segmentTree
{
    struct node
    {
        int l, r;
        int gcd;
    };
    void build(int p, int l, int r)
    {
        t[p] = {l, r};
        if (l == r)
        {
            t[p].gcd = b[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
        t[p].gcd = std::__gcd(t[p << 1].gcd, t[p << 1 | 1].gcd);
    }
    int query(int p, int l, int r)
    {
        if (t[p].r <= r && t[p].l >= l)
        {
            return t[p].gcd;
        }
        int mid = (t[p].l + t[p].r) >> 1;

        if (r <= mid)
        {
            return query(p << 1, l, r);
        }
        else if (l > mid)
        {
            return query(p << 1 | 1, l, r);
        }
        else
        {
            return std::__gcd(query(p << 1, l, mid), query(p << 1 | 1, mid + 1, r));
        }
    }
    explicit segmentTree(int n, std::vector<int> &a) : b(a)
    {
        n_ = (n + 1) << 2;
        t.resize(n_);
        build(1, 1, n);
    }

    std::vector<node> t;
    std::vector<int> &b;
    int n_;
};
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        tmp = std::__gcd(a[i], tmp);
    }
    for (int i = 1; i <= n; i++)
    {
        a.push_back(a[i]);
    }
    segmentTree seg(2 * n, a);
    int l = 0, r = n;
    int res{};
    while (r > l)
    {
        int mid = (l + r) >> 1;
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            a[i] = seg.query(1, i, i + mid);
            if (a[i] != a[1])
                flag = true;
        }
        if (flag)
            l = mid + 1;
        else
            r = mid;
    }
    std::cout << l << "\n";
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