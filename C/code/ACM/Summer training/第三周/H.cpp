#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
int a[N];
struct tree
{
    int l,r;
    bitset<40> sum;
    int tag;
}t[N<<2];
void pushup(int p)
{
    t[p].sum = t[p<<1].sum|t[p<<1|1].sum;
}
void pushdown(int p)
{
    if(t[p].tag)
    {
        t[p<<1].tag = t[p<<1|1].tag = t[p].tag;;
        t[p<<1].sum.reset(),t[p<<1|1].sum.reset();
        t[p<<1].sum[t[p].tag] = 1;
        t[p<<1|1].sum[t[p].tag] = 1;
        t[p].tag = 0;
    }
}
void build(int p,int l,int r)
{
    t[p].l = l; t[p].r = r;
    if(l==r)
    {
        t[p].sum = 1;
        return;
    }
    int mid = (l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
void modifiy(int p,int l,int r,int k)
{
    if(t[p].r<=r&&t[p].l>=l)
    {
        t[p].sum.reset();
        t[p].sum[k] = 1;
        t[p].tag = k;
        return;
    }
    pushdown(p);
    int mid = (t[p].l+t[p].r)>>1;
    if(l<=mid) modifiy(p<<1,l,r,k);
    if(r>mid) modifiy(p<<1|1,l,r,k);
    pushup(p);
}
bitset<40> query(int p,int l,int r)
{
    if(t[p].r<=r&&t[p].l>=l) return t[p].sum;
    pushdown(p);
    int mid = (t[p].l+t[p].r)>>1;
    bitset<40> res = 0;
    if(l<=mid) res|=query(p<<1,l,r);
    if(r>mid) res|=query(p<<1|1,l,r);
    return res;
}
inline void slove()
{
    int n,m,s;
    cin >> n >> s >> m;
    build(1,1,n);
    while(m--)
    {
        char op;
        int l,r,x;
        cin>>op;
        if(op=='C')
        {
            cin >> l >> r >> x;
            if(l>r) swap(l,r);
            modifiy(1,l,r,x);
        }
        else
        {
            cin >> l >> r;
            if(l>r) swap(l,r);
            cout<<query(1,l,r).count()<<endl;
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
}/*
#include <bitset>
#include <iostream>
#include <vector>
struct segmentTree {
    struct node {
        int l, r;
        int lazy;
        std::bitset<32> val;
    };
    segmentTree(int N) {
        t = std::vector<node>((N + 1) << 2);
        build(1, 1, N);
    }
    void pushup(int p) {
        t[p].val = t[p << 1].val | t[p << 1 | 1].val;
    }
    void pushdown(int p) {
        if (t[p].lazy) {
            t[p << 1].lazy = t[p << 1 | 1].lazy = t[p].lazy;
            t[p << 1].val.reset(), t[p << 1 | 1].val.reset();
            t[p << 1].val[t[p].lazy] = 1, t[p << 1 | 1].val[t[p].lazy] = 1;
            t[p].lazy = 0;
        }
    }
    void build(int p, int l, int r) {
        t[p] = {l, r};
        if (l == r) {
            t[p].val[1] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }
    void modify(int p, int l, int r, int k) {
        if (t[p].r <= r && t[p].l >= l) {
            t[p].val.reset();
            t[p].val[k] = 1;
            t[p].lazy = k;
            return;
        }
        pushdown(p);
        int mid = (t[p].l + t[p].r) >> 1;
        if (r <= mid) {
            modify(p << 1, l, r, k);
        } else if (l > mid) {
            modify(p << 1 | 1, l, r, k);
        } else {
            modify(p << 1, l, mid, k), modify(p << 1 | 1, mid + 1, r, k);
        }
        pushup(p);
    }
    std::bitset<32> query(int p, int l, int r) {
        if (t[p].r <= r && t[p].l >= l) {
            return t[p].val;
        }
        pushdown(p);
        int mid = (t[p].l + t[p].r) >> 1;
        if (r <= mid) {
            return query(p << 1, l, r);
        } else if (l > mid) {
            return query(p << 1 | 1, l, r);
        } else {
            return query(p << 1, l, mid) | query(p << 1 | 1, mid + 1, r);
        }
    }
    std::vector<node> t;
};
int main() {
    int n, t, m;
    std::cin >> n >> t >> m;
    segmentTree seg(n);
    while (m--) {
        char op;
        int l, r, k;
        std::cin >> op;
        if (op == 'C') {
            std::cin >> l >> r >> k;
            if (l > r) std::swap(l, r);
            seg.modify(1, l, r, k);
        } else {
            std::cin >> l >> r;
            if (l > r) std::swap(l, r);
            std::cout << seg.query(1, l, r).count() << "\n";
        }
    }
}
*/