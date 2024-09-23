#include <bits/stdc++.h>

#define int long long

const int inf = 1e8;

int ne[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

signed main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> mp(n);
	for (auto &i : mp) std::cin >> i;
	std::array<int, 5> x, y;
	for (int i = 0; i < 5; i++)	{
		std::cin >> x[i]  >> y[i];
		x[i]--, y[i]--;
	}
	std::array<int, 4> t{};
	for(int i = 1; i <= 3; i++) std::cin >> t[i];

	std::array<int, 3> p{1, 2, 3};

	auto bfs = [&](int a, int b, int idx, int sum, bool tag) -> int{
		std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
		std::queue<std::array<int, 3>> q;
		q.push({a, b, 0});
		vis[a][b] = true;
		while(!q.empty()){
			auto e = q.front();
			q.pop();
			if(e[0] == x[idx] && e[1] == y[idx]){
				return e[2];
			}
			for(int i = 0; i < 4; i++){
				std::array<int, 3> w;
				w[0] = e[0] + ne[i][0];
				w[1] = e[1] + ne[i][1];
				if(w[0] >= 0 && w[0] < n && w[1] >= 0 && w[1] < m && !vis[w[0]][w[1]] && ((tag && mp[w[0]][w[1]] != '#') || !tag)){
					w[2] = e[2] + sum;
					q.push(w);
					vis[w[0]][w[1]] = 1;
				}
			}
		}
		return inf;
	};

	int res = inf;
	do{
		int ans = 0;
		ans += bfs(x[0], y[0], p[0], 1, 0);
		ans += bfs(x[p[0]], y[p[0]], p[1], 1 + t[p[0]], 0);
		ans += bfs(x[p[1]], y[p[1]], p[2], 1 + t[p[0]] + t[p[1]], 0);
		ans += bfs(x[p[2]], y[p[2]], 4, 1 + t[p[0]] + t[p[1]] + t[p[2]], 1);
		// std::cout << ans << '\n';
		res = std::min(res, ans);
	}while(std::next_permutation(p.begin(), p.end()));

	std::cout << res;

	return 0;
}