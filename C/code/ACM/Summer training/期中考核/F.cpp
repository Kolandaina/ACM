#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
int a[N];
struct node
{
    int len;
    int l, r;
} f[N];
struct tree
{
    int l, r;
    int sum;
    int tag;
    int minn;
    bool fun;
} t[N << 2];
void pushup(int p)
{
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
    t[p].minn = min(t[p << 1].minn, t[p << 1 | 1].minn);
    if (t[p << 1].fun && t[p << 1 | 1].fun)
    {
        t[p].fun = true;
    }
    else
    {
        t[p].fun = false;
    }
}
void pushdown(int p)
{
    if (t[p].tag)
    {
        t[p << 1].sum -= t[p].tag * (t[p << 1].r - t[p << 1].l + 1);
        t[p << 1].minn -= t[p].tag;
        if (t[p << 1].minn < 0)
        {
            t[p << 1].fun = false;
        }
        t[p << 1].tag += t[p].tag;

        t[p << 1 | 1].sum -= t[p].tag * (t[p << 1 | 1].r - t[p << 1 | 1].l + 1);
        t[p << 1 | 1].minn -= t[p].tag;
        if (t[p << 1 | 1].minn < 0)
        {
            t[p << 1 | 1].fun = false;
        }
        t[p << 1 | 1].tag += t[p].tag;

        t[p].tag = 0;
    }
}
void bulid(int p, int l, int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].sum = a[l];
        t[p].minn = a[l];
        t[p].fun = true;
        return;
    }
    int mid = (l + r) >> 1;
    bulid(p << 1, l, mid);
    bulid(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void modifiy(int p, int l, int r, int k)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        t[p].sum -= k * (t[p].r - t[p].l + 1);
        t[p].minn -= k;
        if (t[p].minn < 0)
        {
            t[p].fun = false;
        }
        t[p].tag += k;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
        modifiy(p << 1, l, r, k);
    if (r > mid)
        modifiy(p << 1 | 1, l, r, k);
    pushup(p);
}
bool res = true;
bool query(int p, int l, int r)
{
    if (t[p].l >= l && t[p].r <= r)
        return t[p].fun;
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;

    if (l <= mid)
        if (query(p << 1, l, r) == false)
        {
            res = false;
        }
    if (r > mid)
        if (query(p << 1 | 1, l, r) == false)
        {
            res = false;
        }
    return res;
}
inline void slove()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    bulid(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        cin >> f[i].len >> f[i].l >> f[i].r;
    }
    bool flag = true;
    for (int i = 1; i <= m; i++)
    {
        modifiy(1, f[i].l, f[i].r, f[i].len);
        res = true;
        if (query(1, f[i].l, f[i].r) == false)
        {
            cout << -1 << endl;
            cout << i << endl;
            flag = false;
            break;
        }
    }
    if (flag)
        cout << 0 << endl;
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