#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5e6 + 10;
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
        t[p<<1].sum += t[p].tag * (t[p<<1].r - t[p<<1].l + 1);
        t[p << 1 | 1].sum += t[p].tag * (t[p<<1 | 1].r - t[p << 1 | 1].l + 1);
        t[p<<1].tag += t[p].tag;
        t[p<<1 | 1].tag += t[p].tag;
        t[p].tag = 0;
    }
}
void bulid(int p,int l,int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    bulid(p << 1, l, mid);
    bulid(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void modifiy(int p,int l, int r, int k)
{
    if ( t[p].l >= l && t[p].r <= r)
    {
        t[p].sum += k * (t[p].r - t[p].l+1);
        t[p].tag += k;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid) modifiy(p << 1, l, r, k);
    if (r > mid) modifiy(p << 1 | 1, l, r, k);
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
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n-1; i >= 0; i--) a[i+1] = a[i+1]-a[i];
    bulid(1, 1, n);
    while(m--)
    {
         int op, x, y, k,d;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k>>d;
            modifiy(1, x, x, k);
            if(x+1<=y)modifiy(1,x+1,y,d);
            if(y<n)modifiy(1,y+1,y+1,-(k+d*(y-x)));
        }
       
        else
        {
            cin >> x;
            cout<<query(1,1,x)<<endl;
        }
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