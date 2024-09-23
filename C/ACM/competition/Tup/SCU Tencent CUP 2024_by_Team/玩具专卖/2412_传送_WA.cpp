#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MAXN = 1e9 + 7, MINN = -(1e9 + 7);
struct Node{
	int l, r;
	int v, flag;
	#define l(x) (x << 1)
	#define r(x) (x << 1 | 1)
}tr[N << 2];
int T;
int n, m;
int maxn[N], minn[N];
namespace Minn{
	inline void pushup(int x)
	{
		tr[x].v = min(tr[l(x)].v, tr[r(x)].v);
	}
	inline void change(int x, int v)
	{
		tr[x].v = min(v, tr[x].v);
		tr[x].flag = min(tr[x].flag, v);
	}
	inline void pushdown(int x)
	{
		if(tr[x].flag == MAXN) return ;
		change(l(x), tr[x].flag), change(r(x), tr[x].flag);
		tr[x].flag = MAXN;
	}
	inline void build(int x, int l, int r)
	{
		tr[x].l = l, tr[x].r = r, tr[x].flag = MAXN;
		if(l == r) return tr[x].v = l, void();
		int mid = l + r >> 1;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
		pushup(x);
	}
	inline void modify(int x, int l, int r, int v)
	{
		if(l <= tr[x].l && tr[x].r <= r) return change(x, v);
		pushdown(x);
		int mid = tr[x].l + tr[x].r >> 1;
		if(l <= mid) modify(x << 1, l, r, v);
		if(r > mid) modify(x << 1 | 1, l, r, v);
		pushup(x);
	}
	inline int query(int x, int l, int r)
	{
		if(l <= tr[x].l && tr[x].r <= r) return tr[x].v;
		pushdown(x);
		int mid = tr[x].l + tr[x].r >> 1, minn = MAXN;
		if(l <= mid) minn = min(minn, query(x << 1, l, r));
		if(r > mid) minn = min(minn, query(x << 1 | 1, l, r));
		return minn;
	}
}
namespace Maxn{
	inline void pushup(int x)
	{
		tr[x].v = max(tr[l(x)].v, tr[r(x)].v);
	}
	inline void change(int x, int v)
	{
		tr[x].v = max(v, tr[x].v);
		tr[x].flag = max(tr[x].flag, v);
	}
	inline void pushdown(int x)
	{
		if(tr[x].flag == MINN) return ;
		change(l(x), tr[x].flag), change(r(x), tr[x].flag);
		tr[x].flag = MINN;
	}
	inline void build(int x, int l, int r)
	{
		tr[x].l = l, tr[x].r = r, tr[x].flag = MINN;
		if(l == r) return tr[x].v = l, void();
		int mid = l + r >> 1;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
		pushup(x);
	}
	inline void modify(int x, int l, int r, int v)
	{
		if(l <= tr[x].l && tr[x].r <= r) return change(x, v);
		pushdown(x);
		int mid = tr[x].l + tr[x].r >> 1;
		if(l <= mid) modify(x << 1, l, r, v);
		if(r > mid) modify(x << 1 | 1, l, r, v);
		pushup(x);
	}
	inline int query(int x, int l, int r)
	{
		if(l <= tr[x].l && tr[x].r <= r) return tr[x].v;
		pushdown(x);
		int mid = tr[x].l + tr[x].r >> 1, maxn = MINN;
		if(l <= mid) maxn = max(maxn, query(x << 1, l, r));
		if(r > mid) maxn = max(maxn, query(x << 1 | 1, l, r));
		return maxn;
	}
}
struct Q{
	int a, b, c, d;
}q[N];
inline bool cmp1(Q x, Q y)
{
	return x.b == y.b ? x.a < y.a : x.b < y.b;
}
inline bool cmp2(Q x, Q y)
{
	return x.a == y.a ? x.b > y.b : x.a > y.a;
}
inline void getminn()
{
	sort(q + 1, q + m + 1, cmp1);
	Minn:: build(1, 1, n);
	for(int i = 1;i <= m;i ++)
	{
		Minn:: modify(1, q[i].c, q[i].d, Minn:: query(1, q[i].a, q[i].b));
	}
	for(int i = 1;i <= n;i ++) minn[i] = Minn:: query(1, i, i);
}
inline void getmaxn()
{
	sort(q + 1, q + m + 1, cmp2);
	Maxn:: build(1, 1, n);
	for(int i = 1;i <= m;i ++)
	{
		Maxn:: modify(1, q[i].c, q[i].d, Maxn:: query(1, q[i].a, q[i].b));
	}
	for(int i = 1;i <= n;i ++) maxn[i] = Maxn:: query(1, i, i);
}
inline void work()
{
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i ++) minn[i] = i;
	for(int i = 1;i <= n;i ++) maxn[i] = i;
	for(int i = 1;i <= m;i ++)
		scanf("%d %d %d %d", &q[i].c, &q[i].d, &q[i].a, &q[i].b);
	getminn();
	getmaxn();
	for(int i = 1;i <= n;i ++) printf("%d %d\n", minn[i], maxn[i]);
}
int main()
{
	scanf("%d", &T);
	while(T --) work();
	return 0;
}
/*
2
4 0
4 2
1 1 1 3
3 3 1 4
*/
