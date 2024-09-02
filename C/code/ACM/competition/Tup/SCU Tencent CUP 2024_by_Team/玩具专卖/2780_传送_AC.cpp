#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MAXN = 1e9 + 7, MINN = -(1e9 + 7);
int T;
int n, m;
int maxn[N], minn[N];
vector<int> qu;
queue<int> s;
namespace Tr{
	struct Node{
		int l, r;
		vector<int> s;
		#define l(x) (x << 1)
		#define r(x) (x << 1 | 1)
	}tr[N << 2];
	inline void build(int x, int l, int r)
	{
		tr[x].l = l, tr[x].r = r, tr[x].s.clear();
		if(l == r) return ;
		int mid = l + r >> 1;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
	}
	inline void add(int x, int l, int r, int id)
	{
		if(l <= tr[x].l && tr[x].r <= r) return tr[x].s.push_back(id), void();
		int mid = tr[x].l + tr[x].r >> 1;
		if(l <= mid) add(x << 1, l, r, id);
		if(r > mid) add(x << 1 | 1, l, r, id);
	}
	inline void query(int x, int id)
	{
		for(int i = 0;i < tr[x].s.size();i ++) qu.push_back(tr[x].s[i]);
		tr[x].s.clear();
		if(tr[x].l == tr[x].r) return ;
		int mid = tr[x].l + tr[x].r >> 1;
		if(id <= mid) query(x << 1, id);
		else query(x << 1 | 1, id);
	}
}
namespace pol{
	struct Node{
		int l, r;
		int v, flag; // v not all del
		#define l(x) (x << 1)
		#define r(x) (x << 1 | 1)
	}tr[N << 2];
	inline void pushup(int x)
	{
		tr[x].v = tr[l(x)].v + tr[r(x)].v;
	}
	inline void build(int x, int l, int r)
	{
		tr[x].l = l, tr[x].r = r;
		if(l == r) return tr[x].v = 1, void();
		int mid = l + r >> 1;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
		pushup(x);
	}
	inline void del(int x, int l, int r)
	{
		if(tr[x].v == 0) return ;
		if(tr[x].l == tr[x].r) return tr[x].v = 0, s.push(tr[x].l), void();
		int mid = tr[x].l + tr[x].r >> 1;
		if(l <= mid) del(x << 1, l, r);
		if(r > mid) del(x << 1 | 1, l, r);
		pushup(x);
	}
}
struct Q{
	int a, b, c, d; // a b change c d
}q[N];
inline void getminn()
{
	Tr:: build(1, 1, n);
	for(int i = 1;i <= m;i ++) Tr:: add(1, q[i].a, q[i].b, i);
	pol:: build(1, 1, n);
	for(int i = 1;i <= n;i ++)
	{
		if(minn[i] != i) continue;
		s.push(i);
		while(!s.empty())
		{
			int o = s.front();
			s.pop();
			minn[o] = i;
			qu.clear();
			Tr:: query(1, o);
			for(int j = 0;j < qu.size();j ++) 
				pol:: del(1, q[qu[j]].c, q[qu[j]].d);
		}	
	}
}
inline void getmaxn()
{
	Tr:: build(1, 1, n);
	for(int i = 1;i <= m;i ++) Tr:: add(1, q[i].a, q[i].b, i);
	pol:: build(1, 1, n);
	for(int i = n;i >= 1;i --)
	{
		if(maxn[i] != i) continue;
		s.push(i);
		while(!s.empty())
		{
			int o = s.front();
			s.pop();
			maxn[o] = i;
			qu.clear();
			Tr:: query(1, o);
			for(int j = 0;j < qu.size();j ++) 
				pol:: del(1, q[qu[j]].c, q[qu[j]].d);
		}	
	}
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
