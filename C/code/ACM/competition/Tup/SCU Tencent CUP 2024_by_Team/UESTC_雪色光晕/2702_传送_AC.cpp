#include <bits/stdc++.h>
using namespace std;
#define ls L[now]
#define rs R[now]

const int N=1e5+7;
const int inf=0x3f3f3f3f;

inline int read() {
	int sum = 0, ff = 1; char c = getchar();
	while(c<'0' || c>'9') { if(c=='-') ff = -1; c = getchar(); }
	while(c>='0'&&c<='9') { sum = sum * 10 + c -'0'; c = getchar(); }
	return sum * ff;
}


int T;
int n,m;
int a[N];
struct E{
	int l1,r1,l2,r2;
}b[N];
vector <int> e[N*6];
int tot,rt,L[N*6],R[N*6];

int dfn[N*6],low[N*6],st[N*6],cnt,in[N*6],tim;
int num,belong[N*6];
vector <int> d[N*6];
int ansl[N*6], ansr[N*6];
int du[N*6],vis[N*6];

void chushihua() {
	for(int i=1;i<=n;i++) a[i] = 0;
	for(int i=1;i<=tot;i++) e[i].clear(), d[i].clear() ,dfn[i] = low[i] = belong[i] = du[i] = vis[i] = 0;
	tot = tim = cnt = num = 0;
}

void built(int &now,int l,int r) {
	now = ++tot;
	if(l==r) { e[now].push_back(l); return ; }
	int mid = l+r >> 1;
	built(ls, l, mid);
	built(rs, mid+1, r);
	e[now].push_back(ls);
	e[now].push_back(rs);
}

void insert(int now,int l,int r,int x,int y,int gg) {
	if(x<=l && r<=y) { e[gg].push_back(now); return ; }
	int mid = l+r >> 1;
	if(x<=mid) insert(ls, l, mid, x, y, gg);
	if(y>mid)  insert(rs, mid+1, r, x, y, gg);
}

void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	in[u] = 1; st[++cnt] = u;
	for(int v : e[u]) {
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(in[v]) low[u] = min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]) {
		++num;
		while(1) {
			int v = st[cnt--]; in[v] = 0;
			belong[v] = num;
			if(u==v) break;
		}
	}
}

void DFS(int u) {
	vis[u] = 1;
	for(int v : d[u]) {
		if(vis[v]) continue;
		du[v]--;
		ansl[v] = min(ansl[v],ansl[u]);
		ansr[v] = max(ansr[v],ansr[u]);
		if(!du[v]) DFS(v);
	}
}

int main() {
	int T=read();
	while(T--) {
		chushihua();
		n = read(); m = read(); tot = n;
		built(rt, 1, n);
		for(int i=1;i<=m;i++) {
			b[i].l1 = read(); b[i].r1 = read(); b[i].l2 = read(); b[i].r2 = read();
			a[ b[i].l1 ]++; a[ b[i].r1 ]--;
		}
		for(int i=1;i<n;i++) {
			a[i] += a[i-1];
			if(a[i]>0) e[i].push_back(i+1);
		}
		for(int i=1;i<=m;i++) {
			insert(rt, 1, n, b[i].l2, b[i].r2, b[i].r1);
		}
		for(int i=1;i<=tot;i++) {
			if(!dfn[i]) tarjan(i);
		}
//		for(int i=1;i<=tot;i++) cout<<"belong["<<i<<"] = "<<belong[i]<<"\n";
		for(int u=1;u<=tot;u++) {
			for(int v : e[u]) {
				int uu = belong[u];
				int vv = belong[v];
				if(uu != vv) d[vv].push_back(uu), du[uu]++;//, cout<<vv<<" -> "<<uu<<endl;;
			}
		}
		for(int i=1;i<=num;i++) ansl[i] = inf, ansr[i] = -inf;
		for(int i=1;i<=n;i++) {
			int uu = belong[i];
			ansl[uu] = min(ansl[uu],i);
			ansr[uu] = max(ansr[uu],i);
		}
		for(int i=1;i<=num;i++) {
			if(!vis[i] && !du[i]) DFS(i);
		}
		for(int i=1;i<=n;i++) {
			int uu = belong[i];
			cout<<ansl[uu]<<" "<<ansr[uu]<<endl;
		}
	}
	
	return 0;
}

/*

4
4 0
4 2
1 1 1 3
3 3 1 4
4 0
4 2
1 1 1 3
3 3 1 4

*/

