#include <bits/stdc++.h>

int n;
std::vector<std::vector<std::pair<long long, long long>>> e(1000000);
std::vector<long long> sz(1000000), f(1000000);

void dfs(int u, int fa){
	sz[u] = 1;
	f[u] = 0;
	for(auto i : e[u]){
		int x = i.first, y = i.second;
		if(x == fa) continue;
		dfs(x, u);
		sz[u] += sz[x];
		f[u] += sz[x] * y + f[x];
	}
};
//第一遍DFS便利出以1为根节点的答案

void get_res(int u, int fa){
	for(auto i : e[u]){
		int x = i.first, y = i.second;
		if(x == fa) continue;
		f[x] = f[u] - sz[x] * y + (n - sz[x]) * y;
		get_res(x, u);
	}
}
//第二遍递归便利更新以每个节点为根时候的答案

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	
	for(int i = 0; i < n - 1; i++){
		long long u, v, w;
		std::cin >> u >> v >> w ;
		u--, v--;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}

	dfs(0, 0);
	get_res(0, 0);

	for(int i = 0; i < n; i++) std::cout << f[i] << " \n"[i == n - 1];

	return 0;
}