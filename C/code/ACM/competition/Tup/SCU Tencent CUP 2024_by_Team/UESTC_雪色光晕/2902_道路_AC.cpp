#include <bits/stdc++.h>
using namespace std;

const int N=2e5+7;
const int inf=0x3f3f3f3f;

inline int read() {
	int sum = 0, ff = 1; char c = getchar();
	while(c<'0' || c>'9') { if(c=='-') ff = -1; c = getchar(); }
	while(c>='0'&&c<='9') { sum = sum * 10 + c -'0'; c = getchar(); }
	return sum * ff;
}

int a[N],dep[N];
vector<int> g[N];

int dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	int ret=0;
	if(!g[u].size())
		return u;
	for(int v:g[u]){
		int x=dfs(v,u);
		if(dep[x]<dep[ret])
			ret=x;
	}
	if(u!=1) a[ret]++;
	return ret;
}

int main() {
	int n=read();
	for(int i=2;i<=n;i++)
		g[read()].push_back(i);
	dep[0]=n+1,dfs(1,1);
	int Min=n,Max=0;
	for(int i=1;i<=n;i++)
		if(!g[i].size())
			Min=min(Min,a[i]),Max=max(Max,a[i]);
	printf("%d",Max-Min);
	return 0;
}
