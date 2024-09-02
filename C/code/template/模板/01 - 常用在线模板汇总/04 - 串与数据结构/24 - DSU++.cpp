struct DSU {
	std::vector<int> fa, p, e, f;
	DSU(int n) {
		fa.resize(n + 1);
		std::iota(fa.begin(), fa.end(), 0);
		p.resize(n + 1, 1);
		e.resize(n + 1);
		f.resize(n + 1);
	}
	int find(int x) {
		while (x != fa[x]) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	}
	bool merge(int x, int y) { // 设x是y的祖先
		if (x == y) f[find(x)] = 1;
		x = find(x), y = find(y);
		e[x]++;
		if (x == y) return false;
		if (x < y) std::swap(x, y); // 将编号小的合并到大的上
		fa[y] = x;
		f[x] |= f[y], p[x] += p[y], e[x] += e[y];
		return true;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	bool F(int x) { // 判断连通块内是否存在自环
		return f[find(x)];
	}
	int size(int x) { // 输出连通块中点的数量
		return p[find(x)];
	}
	int E(int x) { // 输出连通块中边的数量
		return e[find(x)];
	}
};
