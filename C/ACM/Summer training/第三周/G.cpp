#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5e5 + 10;
int a[N];
struct tree
{
    int l,r;
    int sum;
    int tag;
}t[N << 2];
void pushup(int p)
{
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}
void pushdown(int p)
{
    if (t[p].tag)
    {
        t[p<<1].sum = (t[p<<1].r - t[p<<1].l + 1)-t[p<<1].sum;
        t[p << 1 | 1].sum = (t[p<<1 | 1].r - t[p << 1 | 1].l + 1)-t[p<<1|1].sum;
        if(t[p<<1].tag==0) t[p<<1].tag = 1;
        else t[p<<1].tag = 0;
        if(t[p<<1|1].tag==0) t[p<<1|1].tag = 1;
        else t[p<<1|1].tag = 0;
        t[p].tag = 0;
    }
}
void bulid(int p,int l,int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].sum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    bulid(p << 1, l, mid);
    bulid(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void modifiy(int p,int l, int r)
{
    if ( t[p].l >= l && t[p].r <= r)
    {
        t[p].sum = (t[p].r - t[p].l+1)-t[p].sum;
        if(t[p].tag==0) t[p].tag = 1;
        else t[p].tag = 0;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid) modifiy(p << 1, l, r);
    if (r > mid) modifiy(p << 1 | 1, l, r);
    pushup(p);
}
int query(int p, int l, int r)
{
    if (t[p].l>=l&&t[p].r<=r) return t[p].sum;
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    int res = 0;
    if (l <= mid) res += query(p<<1, l, r);
    if(r > mid) res += query(p << 1 | 1, l, r);
    return res;
}
inline void slove()
{
    int n, m;
    cin >> n >> m;
    bulid(1, 1, n);
    while(m--)
    {
         int op, x, y;
        cin >> op >> x >> y;
        if(op) cout<<query(1,x,y)<<endl;
        else modifiy(1,x,y);
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