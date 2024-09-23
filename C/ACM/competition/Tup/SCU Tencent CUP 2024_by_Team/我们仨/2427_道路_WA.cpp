#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N=2e5+10;
int n;
vector<vector<pair<int, int> > > E;
int d[N], a[N];
int maxx, minx;

void dfs(int u) {
	d[u] = 1;
	for (int i=0;i<E[u].size();++i) {
		int v = E[u][i].second;
		dfs(v);
		E[u][i].first = d[v];
		d[u] = max(d[v]+1,d[u]);
	}
	sort(E[u].begin(),E[u].end());
}

void dfs2(int u, int value) {
	if (E[u].size() == 0) {
		maxx=max(maxx,value);
		minx=min(minx,value);
		return;
	}
	dfs2(E[u][0].second,value+1);
	for (int i=0;i<E[u].size();++i) {
		int v = E[u][i].second;
		dfs2(v, 1);
	}
}

int main() {
	scanf("%d",&n);
	E.resize(n+1);
	maxx=1;
	minx=n;
	for(int i=2,x;i<=n;++i) {
		scanf("%d",&x);
		E[x].push_back(make_pair(1, i));
	}
	dfs(1);
//	for (int i=1;i<=n;++i) {
//		for (int j=0;j<E[i].size();++j) {
//			printf("(%d,%d) ", E[i][j].second, E[i][j].first);
//		}
//		putchar('\n');
//	}
	dfs2(1,1);
	printf("%d\n",maxx-minx);
	return 0;
}

