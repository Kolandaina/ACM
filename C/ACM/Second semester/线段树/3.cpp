#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N + 1];
struct tree
{
    int l, r;
    int sum, maxv;
    int tag;
} t[N << 2];
void pushup(int p)
{
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
    t[p].maxv = max(t[p << 1].maxv, t[p << 1 | 1].maxv);
}
void pushdown(int p)
{
    if (t[p].tag)
    {
        t[p << 1].sum += t[p].tag * (t[p << 1].r - t[p << 1].l + 1);
        t[p << 1 | 1].sum += t[p].tag * (t[p << 1 | 1].r - t[p << 1 | 1].l + 1);
        t[p << 1].tag += t[p].tag, t[p << 1 | 1].tag += t[p].tag;
        t[p].tag = 0;
    }
}
void build(int p, int l, int r)
{
    t[p] = {l, r};
    if (l == r)
    {
        t[p].sum = a[l];
        t[p].maxv = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void modifiy(int p, int l, int r, int k)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        t[p].sum += k * (t[p].r - t[p].l + 1);
        t[p].tag += k;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
    {
        modifiy(p << 1, l, r, k);
    }
    if (r > mid)
    {
        modifiy(p << 1 | 1, l, r, k);
    }
    pushup(p);
}
int query_sum(int p, int l, int r)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        return t[p].sum;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    int res = 0;
    if (l <= mid)
    {
        res += query_sum(p << 1, l, r);
    }
    if (r > mid)
    {
        res += query_sum(p << 1 | 1, l, r);
    }
    return res;
}
int query_max(int p, int l, int r)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        return t[p].maxv;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    int res = INT_MIN;
    if (l <= mid)
    {
        res = max(res, query_max(p << 1, l, r));
    }
    if (r > mid)
    {
        res = max(res, query_max(p << 1 | 1, l, r));
    }
    return res;
}
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--)
    {
        int op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            modifiy(1, x, y, k);
        }
        else if (op == 2)
        {
            cin >> x >> y;
            cout << query_sum(1, x, y) << endl;
        }
        else if (op == 3)
        {
            cin >> x >> y;
            cout << query_max(1, x, y) << endl;
        }
    }
    return 0;
}
