#include<bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<int>> e(n);
	for (int i = 1; i < n; ++i)  {
		int x;
		cin >> x;
		--x;
		e[x].push_back(i);
	}
	vector<int> f(n);
	int mx=-1,mi=n+1;
	auto dfs = [&](auto &&self, int u) -> void {
		f[u]=n+1;
		for (int v : e[u]) {
			self(self, v);
			f[u]=min(f[u],f[v]+1);
		}
		if(f[u]==n+1)f[u]=1;
		int flag=0;
		for (int v : e[u]) {
			if(f[v]+1==f[u])
			{
				if(flag)
				{
					mx=max(mx,f[v]);
					mi=min(mi,f[v]);
				}
				else flag=1;
			}
			else 
			{
				mx=max(mx,f[v]);
				mi=min(mi,f[v]);
			}
		}	
	};
	dfs(dfs, 0);
	f[0]-=1;
	mx=max(mx,f[0]);
	mi=min(mi,f[0]);
	cout << mx-mi << '\n';
	return 0;
}

