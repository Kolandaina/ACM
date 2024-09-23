#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5e5 + 10;
int a[N];
struct tree
{
    int l, r;
    int sum;
    int maxn;
    int tag;
} t[N << 2];
int jishu(int x)
{
    int res = 0;
    while (x > 0)
        res += x % 10, x /= 10;
    return res;
}
void pushup(int p)
{
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
    t[p].maxn = max(t[p << 1].maxn,t[p << 1|1].maxn);
}
void pushdown(int p)
{
    if (t[p].tag)
    {
        t[p << 1].sum += t[p].tag * (t[p << 1].r - t[p << 1].l + 1);
        t[p << 1 | 1].sum += t[p].tag * (t[p << 1 | 1].r - t[p << 1 | 1].l + 1);
        t[p << 1].tag += t[p].tag;
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
        t[p].maxn = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    bulid(p << 1, l, mid);
    bulid(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void modifiy(int p, int l, int r)
{
    if(t[p].maxn<=9) return;
    if (t[p].l ==t[p].r)
    {
        t[p].maxn = t[p].sum=jishu(t[p].sum);
        return;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
        modifiy(p << 1, l, r);
    if (r > mid)
        modifiy(p << 1 | 1, l, r);
    pushup(p);
}
int query(int p, int l, int r)
{
    if (t[p].l >= l && t[p].r <= r)
        return t[p].sum;
    int mid = (t[p].l + t[p].r) >> 1;
    int res = 0;
    if (l <= mid)
        res += query(p << 1, l, r);
    if (r > mid)
        res += query(p << 1 | 1, l, r);
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
    while (m--)
    {
        int op,x,y;
        cin >> op >> x;
        if (op == 1)
        {
            cin >> y;
            modifiy(1, x, y);
        }
        else
            cout << query(1, x, x) << endl;
    }
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