#include<vector>
struct Tree {
	int n;
	std::vector<std::vector<int>> ver, val;
	std::vector<int> lg, deep;
	Tree (int n) {
		this->n = n;
		ver.resize (n + 1);
		val.resize (n + 1, std::vector<int> (30));
		lg.resize (n + 1);
		deep.resize (n + 1);
		for (int i = 1; i <= n; i++) {
			lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
		}
	}
	void add (int x, int y) {
		ver[x].push_back (y);
		ver[y].push_back (x);
	}
	void dfs (int x, int fa) {
		val[x][0] = fa;
		deep[x] = deep[fa] + 1;
		for (int i = 1; i <= lg[deep[x]]; i++) {
			val[x][i] = val[val[x][i - 1]][i - 1];
		}
		for (auto y : ver[x]) {
			if (y == fa) continue;
			dfs (y, x);
		}
	}
	int lca (int x, int y) {
		if (deep[x] < deep[y]) std::swap (x, y);
		while (deep[x] > deep[y]) {
			x = val[x][lg[deep[x] - deep[y]] - 1];
		}
		if (x == y) return x;
		for (int k = lg[deep[x]] - 1; k >= 0; k--) {
			if (val[x][k] == val[y][k]) continue;
			x = val[x][k];
			y = val[y][k];
		}
		return val[x][0];
	}
	int clac (int x, int y) {
		return deep[x] + deep[y] - 2 * deep[lca (x, y)];
	}
	void work (int root = 1) {
		dfs (root, 0);
	}
};
