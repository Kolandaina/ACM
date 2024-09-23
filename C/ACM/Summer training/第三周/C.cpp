#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
int a[N];
struct tree
{
    int l,r;
    int sum;
    int tag1,tag2;
    bool flag;
}t[N << 2];
void pushup(int p)
{
    t[p].sum = max(t[p << 1].sum, t[p << 1 | 1].sum);
}
void pushdown(int p)
{
    if(t[p].flag)
    {
        t[p<<1].tag1 = t[p].tag1;
        t[p<<1].tag2 = t[p].tag2;
        t[p<<1].sum = t[p].tag1 + t[p].tag2;

        t[p<<1|1].tag1 = t[p].tag1;
        t[p<<1|1].tag2 = t[p].tag2;
        t[p<<1|1].sum = t[p].tag1+t[p].tag2;
        
        t[p<<1].flag = t[p<<1|1].flag = true;
    }
    else
    {
        t[p<<1].tag2 += t[p].tag2,t[p<<1|1].tag2 += t[p].tag2;
        t[p<<1].sum += t[p].tag2,t[p<<1|1].sum+=t[p].tag2;
    }
    t[p].flag = false;
    t[p].tag2 = t[p].tag1 = 0;
}
void bulid(int p,int l,int r)
{
    t[p].l = l;
    t[p].r = r;
    t[p].sum = -1e18;
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
        t[p].tag2 += k;
        t[p].sum += k;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid) modifiy(p << 1, l, r, k);
    if (r >= mid +1) modifiy(p << 1 | 1, l, r, k);
    pushup(p);
}
void modifiy_change(int p,int l, int r, int k)
{
    if(l<=t[p].l&&r>=t[p].r)
    {
        t[p].tag1 = k;
        t[p].tag2 = 0;
        t[p].sum  = k;
        t[p].flag = true;
        return;
    }
    pushdown(p);
    int mid = (t[p].l+t[p].r)>>1;
    if(l<=mid) modifiy_change(p<<1,l,r,k);
    if(r>=mid+1) modifiy_change(p<<1|1,l,r,k);
    pushup(p);
}
int query(int p, int l, int r)
{
    if (t[p].l>=l&&t[p].r<=r) return t[p].sum;
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    int res = -1e18;
    if (l <= mid) res =max(res,query(p<<1,l,r));
    if(r >=mid+1) res =max(res, query(p << 1 | 1, l, r));
    return res;
}
inline void slove()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bulid(1, 1, n);
    while(m--)
    {
         int op, x, y, k;
        cin >> op >> x >> y;
        if(x > y) swap(x,y);
        if (op == 2)
        {
            cin >> k;
            modifiy(1, x, y, k);
        }
        else if (op == 3)
        {
            cout << query(1, x, y) << endl;
        }
        else
        {
            cin >> k;
            modifiy_change(1,x,y,k);
        }
    }
}
signed main()
{
    cin.sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}