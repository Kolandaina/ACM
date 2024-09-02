#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod;
const int N = 2e5 + 10;
struct node
{
    int l,r;
    int maxn;
}t[N<<2];
void build(int p,int l,int r)
{
    t[p] = {l,r};
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1,l,mid),build(p<<1|1,mid+1,r);
    t[p].maxn = max(t[p<<1].maxn,t[p<<1|1].maxn);
}
void modify(int p,int v,int k)
{
    if (t[p].l == v && t[p].r == v)
    {
        t[p].maxn = k;
        return;
    }
    int mid = (t[p].l + t[p].r)>>1;
    if (v <= mid)
    {
        modify(p<<1,v,k);
    }
    else
    {
        modify(p<<1|1,v,k);
    }
    t[p].maxn = max(t[p<<1].maxn,t[p<<1|1].maxn);
}
int query(int p, int l, int r)
{
    if (t[p].l>= l && t[p].r<=r)
    {
        return t[p].maxn;
    }
    int mid = (t[p].l + t[p].r)>> 1;
    int res = LLONG_MIN;
    if(r<=mid)
    {
        res = max(res, query(p<<1,l,r));
    }
    else if(l>mid)
    {
        res = max(res, query(p<<1|1,l,r));
    }
    else res = max(query(p<<1,l,r),query(p<<1|1,l,r));
    return res;
}
signed main() {
    int m,cur = 0,last = 0;
    cin >> m >> mod;
    build(1,1,m);
    while(m--)
    {
        char op;
        int k;
        cin>>op>>k;
        if(op=='A')
        {
            modify(1,++cur,(k+last)%mod);
        }
        else
        {
            last = query(1,cur-k+1,cur);
            cout<<last<<endl;
        }
    }
    return 0;
}