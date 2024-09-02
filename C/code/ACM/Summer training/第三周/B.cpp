/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+7;
template<typename T>void read(T &x)
{
    x=0;char ch=getchar();ll f=1;
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}x*=f;
}
ll n,m,arr[N],mod,flag,cn,cm,cw;
struct node
{
    ll l,r,sum,mul,add;
}tree[N];

inline void build(ll i,ll l,ll r)
{
    tree[i].l=l;
    tree[i].r=r;
    tree[i].mul=1;
    if(l==r)
    {
        tree[i].sum=arr[l]%mod;
        return ;
    }
    ll mid=(l+r)>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%mod;
}
inline void push_down(ll i)
{
    tree[i*2].sum=(ll)(tree[i].mul*tree[i*2].sum+((tree[i*2].r-tree[i*2].l+1)*tree[i].add)%mod)%mod;
    tree[i*2+1].sum=(ll)(tree[i].mul*tree[i*2+1].sum+((tree[i*2+1].r-tree[i*2+1].l+1)*tree[i].add)%mod)%mod;
    tree[i*2].mul=(ll)(tree[i*2].mul*tree[i].mul)%mod;
    tree[i*2+1].mul=(ll)(tree[i*2+1].mul*tree[i].mul)%mod;
    tree[i*2].add=(ll)(tree[i*2].add*tree[i].mul+tree[i].add)%mod;
    tree[i*2+1].add=(ll)(tree[i*2+1].add*tree[i].mul+tree[i].add)%mod;
    tree[i].mul=1;tree[i].add=0;
}
inline void add(ll i,ll l,ll r,ll k)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].add=(ll)(tree[i].add+k)%mod;
        tree[i].sum=(ll)(tree[i].sum+k*(tree[i].r-tree[i].l+1))%mod;
        return ;
    }
    push_down(i);
  
    if(tree[i*2].r>=l)
        add(i*2,l,r,k);
    if(tree[i*2+1].l<=r)
        add(i*2+1,l,r,k);
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%mod;
}
inline void mult(ll i,ll l,ll r,ll k)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].mul=(tree[i].mul*k)%mod;
        tree[i].add=(tree[i].add*k)%mod;
        tree[i].sum=(tree[i].sum*k)%mod;
        return ;
    }
    push_down(i);
    if(tree[i*2].r>=l)
        mult(i*2,l,r,k);
    if(tree[i*2+1].l<=r)
        mult(i*2+1,l,r,k);
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%mod;
}
inline ll query(ll i,ll l,ll r)
{
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].sum;
    push_down(i);
    ll num=0;
    if(tree[i*2].r>=l)
        num=(num+query(i*2,l,r))%mod;
    if(tree[i*2+1].l<=r)
        num=(num+query(i*2+1,l,r))%mod;
    return num;
}
int main()
{
    read(n),read(m),read(mod);
    for(int i=1;i<=n;++i)
        read(arr[i]);
    build(1,1,n);
    for(int i=1;i<=m;++i)
    {
        read(flag);
        if(flag==1)
        {
            read(cn),read(cm),read(cw);
            mult(1,cn,cm,cw);
        }
        else if(flag==2){
            read(cn),read(cm),read(cw);
            add(1,cn,cm,cw);
        }
        else {
            read(cn),read(cm);
            cout<<query(1,cn,cm)<<endl;
        }
    }
}


*/#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5e6 + 10;
int a[N];
int mod;
struct tree
{
    int l,r;
    int sum;
    int tag;
    int mul;
}t[N << 2];
void pushup(int p)
{
    t[p].sum = (t[p << 1].sum + t[p << 1 | 1].sum) % mod;
}
void pushdown(int p)
{
    if (t[p].tag)
    {
        t[p<<1].sum = ((t[p].tag * (t[p<<1].r - t[p<<1].l + 1))%mod + t[p<<1].sum*t[p].mul)%mod;
        t[p << 1 | 1].sum = ((t[p].tag * (t[p<<1 | 1].r - t[p << 1 | 1].l + 1))%mod+t[p<<1|1].sum*t[p].mul)%mod;
        t[p<<1].tag =(t[p<<1].tag+ t[p].tag) % mod;
        t[p<<1 | 1].tag = (t[p<<1|1].tag + t[p].tag)% mod;
        t[p<<1].mul = (t[p<<1].mul*t[p].mul)%mod;
        t[p<<1|1].mul = (t[p<<1|1].mul*t[p].mul)%mod;
        t[p].mul = 1;
        t[p].tag = 0;
    }
}
void bulid(int p,int l,int r)
{
    t[p].l = l;
    t[p].r = r;
    t[p].mul = 1;
    if (l == r)
    {
        t[p].sum = a[l]%mod;
        return;
    }
    int mid = (l + r) >> 1;
    bulid(p << 1, l, mid);
    bulid(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void multl(int p,int l,int r,int k)
{
    if(t[p].l>=l&&t[p].r<=r)
    {
        t[p].mul = (t[p].mul*k)%mod;
        t[p].sum = (t[p].sum*k)%mod;
        t[p].tag = (t[p].tag*k)%mod;
        return;
    }
    pushdown(p);
    int mid = (t[p].l+t[p].r)>>1;
    if(l<=mid) multl(p<<1,l,r,k);
    if(r>mid) multl(p<<1|1,l,r,k);
    pushup(p);
}
void modifiy(int p,int l, int r, int k)
{
    if ( t[p].l >= l && t[p].r <= r)
    {
        t[p].sum =(t[p].sum+ k * (t[p].r - t[p].l+1)) % mod;
        t[p].tag =(t[p].tag+ k) % mod;
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
    if(l<=mid) res = (res+query(p << 1, l, r))%mod;
    if(r>mid) res = (res+query(p << 1 | 1, l, r))%mod;
    return res%mod;
}
inline void slove()
{
    int n, m;
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bulid(1, 1, n);
    while(m--)
    {
         int op, x, y, k;
        cin >> op;
        if (op == 2)
        {
            cin >> x >> y >> k;
            if(x > y) swap(x,y);
            modifiy(1, x, y, k);
        }
        if(op == 3)
        {
            cin >> x >> y;
            if(x > y) swap(x,y);
            cout << query(1, x, y) << endl;
        }
        if(op == 1)
        {
            cin >> x >> y >> k;
            if(x > y) swap(x,y);
            multl(1,x,y,k);
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