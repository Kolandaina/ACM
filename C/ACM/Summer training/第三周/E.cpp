#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5e5+10;
int a[N];
struct tree
{
    int l,r;
    int sum;
    int maxn,minn;
    int tag;
}t[N<<2];
void pushup(int p)
{
    t[p].sum = t[p<<1].sum+t[p<<1|1].sum;
    t[p].maxn = max(t[p<<1].maxn,t[p<<1|1].maxn);
    t[p].minn = min(t[p<<1].minn,t[p<<1|1].minn);
}
void pushdown(int p)
{
    if(t[p].tag)
    {
        t[p<<1].tag += t[p].tag;
        t[p<<1].sum = t[p<<1].sum -(t[p<<1].r-t[p<<1].l+1)*t[p].tag;
        t[p<<1].maxn -= t[p].tag;
        t[p<<1].minn -= t[p].tag;

        t[p<<1|1].tag += t[p].tag;
        t[p<<1|1].sum = t[p<<1|1].sum -(t[p<<1|1].r-t[p<<1|1].l+1)*t[p].tag;
        t[p<<1|1].maxn -= t[p].tag;
        t[p<<1|1].minn -= t[p].tag;

        t[p].tag = 0;
        return;
    }
}
void build(int p,int l,int r)
{
    t[p].l = l; t[p].r = r;
    if(l==r)
    {
        t[p].sum = a[l];
        t[p].maxn = a[l];
        t[p].minn = a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
void modifiy(int p, int l, int r)
{
    if(t[p].l>=l && t[p].r<=r && (t[p].minn-(long long)sqrt(t[p].minn))==(t[p].maxn-(long long)sqrt(t[p].maxn))){
        long long u=t[p].minn-(long long)sqrt(t[p].minn);
        t[p].tag+=u;
        t[p].sum-=(t[p].r-t[p].l+1)*u;
        t[p].minn-=u;
        t[p].maxn-=u;
        return ;
    }
    if(t[p].r<l || t[p].l>r)  return ;
    pushdown(p);
    if(t[p*2].r>=l)  modifiy(p*2,l,r);
    if(t[p*2+1].l<=r)  modifiy(p*2+1,l,r);
    pushup(p);
    return ;
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
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    cin>>m;
    while(m--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(x>y)swap(x,y);
        if(op==1) cout<<query(1,x,y)<<endl;
        else modifiy(1,x,y);
    }
}
signed main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}