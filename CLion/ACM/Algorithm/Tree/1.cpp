#include <iostream>
using namespace std;
#define int long long
const int N = 1000000;
int a[N];
struct tree
{
    int l,r;
    int sum;
}t[N<<2];
void pushup(int p)
{
    t[p].sum = t[p<<1].sum + t[p<<1|1].sum;
}
void build(int p, int l, int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].sum = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(p<<1, l,mid),build(p<<1|1, mid+1, r);
    pushup(p);
}
void modifiy(int p, int v, int k)
{
    if (t[p].l == v && t[p].r == v)
    {
        t[p].sum += k;
        return;
    }
    int mid = (t[p].l+t[p].r)>>1;
    if (v<=mid)
    {
        modifiy(p<<1,v,k);
    }
    else
    {
        modifiy(p<<1|1,v,k);
    }
    pushup(p);
}
int query(int p,int l,int r)
{
    if (t[p].l>=l&&t[p].r<=r)
    {
        return t[p].sum;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    int res = 0;
    if (r <= mid)
    {
        res += query(p << 1, l, r);
    }
    else if (l > mid)
    {
        res += query(p << 1 | 1, l, r);
    }
    else
    {
        res += query(p << 1, l, mid) + query(p << 1 | 1, mid + 1, r);
    }
    return res;
}
signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    while(m--)
    {
        int op,l,r;
        cin>>op>>l>>r;
        if (op == 1) {
            modifiy(1, l, r);
        }
        else {
            cout << query(1, l, r) << endl;
        }
    }
    return 0;
}