#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 10;
int t, n, m, p;
typedef struct Node
{
    int l, r;
    int ki[2];
    int sum[2];
    friend Node operator+(const Node &x, const Node &y)
    {
        Node z;
        z.sum[0] = (x.sum[0] + y.sum[0]) % p;
        z.sum[1] = ((x.sum[1] + y.sum[1]) % p + x.sum[0] * y.sum[0] % p) % p;
        return z;
    }
} Node;
Node tr[N * 4];
int a[N];
void init_lazy(int u)
{
    tr[u].ki[0] = 0;
    tr[u].ki[1] = 1;
}
void pushup(int u)
{
    tr[u].sum[0] = (tr[u << 1].sum[0] + tr[u << 1 | 1].sum[0]) % p;
    tr[u].sum[1] = ((tr[u << 1].sum[1] + tr[u << 1 | 1].sum[1]) % p +
                    tr[u << 1].sum[0] * tr[u << 1 | 1].sum[0] % p) %
                   p;
}
void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    init_lazy(u);
    if (l == r)
    {
        tr[u].sum[0] = a[l];
        tr[u].sum[1] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void cal_lazy(int fa, int ch)
{
    int a = tr[fa].ki[1], b = tr[fa].ki[0];
    int len = tr[ch].r - tr[ch].l + 1;
    tr[ch].sum[1] = (a * a % p * tr[ch].sum[1] % p +
                     a * b % p * (len - 1) % p * tr[ch].sum[0] % p +
                     (len - 1) * len / 2 % p * b % p * b % p) %
                    p;
    tr[ch].sum[0] = (a * tr[ch].sum[0] % p + len * b % p) % p;
}
void tag_union(int fa, int ch)
{
    int a = tr[fa].ki[1], b = tr[fa].ki[0];
    tr[ch].ki[1] = (tr[ch].ki[1] * a) % p;
    tr[ch].ki[0] = (tr[ch].ki[0] * a % p + b) % p;
}
void pushdown(int u)
{
    if (tr[u].ki[0] != 0 || tr[u].ki[1] != 1)
    {
        cal_lazy(u, u << 1);
        cal_lazy(u, u << 1 | 1);
        tag_union(u, u << 1);
        tag_union(u, u << 1 | 1);
        init_lazy(u);
    }
}
void modify(int u, int l, int r, int k, int type)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        if (type == 1)
        {
            int len = tr[u].r - tr[u].l + 1;
            tr[u].sum[1] =
                (tr[u].sum[1] + k * (len - 1) % p * tr[u].sum[0] % p +
                 len * (len - 1) / 2 % p * k % p * k % p) %
                p;
            tr[u].sum[0] = (tr[u].sum[0] + k * len % p) % p;
            tr[u].ki[0] = (tr[u].ki[0] + k) % p;
        }
        else
        {
            tr[u].sum[1] = (tr[u].sum[1] * k % p * k) % p;
            tr[u].sum[0] = (tr[u].sum[0] * k) % p;
            tr[u].ki[1] = (tr[u].ki[1] * k) % p;
            tr[u].ki[0] = (tr[u].ki[0] * k) % p;
        }
        return;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) modify(u << 1, l, r, k, type);
    if (r > mid) modify(u << 1 | 1, l, r, k, type);
    pushup(u);
}
Node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    Node res;
    if (l > mid)
    {
        return query(u << 1 | 1, l, r);
    }
    else if (r <= mid)
    {
        return query(u << 1, l, r);
    }
    else
    {
        res = query(u << 1, l, r) + query(u << 1 | 1, l, r);
        return res;
    }
}
signed main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &p);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        build(1, 1, n);
        int opt, l, r, v;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &opt, &l, &r);
            if (opt <= 2)
            {
                scanf("%d", &v);
                modify(1, l, r, v, opt);
            }
            else
            {
                Node res = query(1, l, r);
                printf("%intd\n", res.sum[1]);
            }
        }
    }
}
