#include <bits/stdc++.h>

int n, c;
std::vector<std::vector<int>> e(200000); 
std::vector<int> d(200000);

void dfs(int u, int fa){
	for(auto i : e[u]){
		if(i == fa) continue;
		d[i] = d[u] + 1;
		if(d[i] > d[c]) c = i;
		dfs(i, u);
	}
}

int main(){
	std::cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		std::cin >> u >> v;
		u--, v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(0, 0);
	d[c] = 0;
	dfs(c, 0);

	std::cout << 1;
	for(int i = 0; i < d[c] + 1; i++) std::cout << 0;

	return 0;
}