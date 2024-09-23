struct DSU {
    std::vector<int> fa, p;
    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        p.resize(n + 1, 1);
    }
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (x < y) std::swap(x, y);
        fa[y] = x;
        p[x] += p[y];
        return true;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
    int size(int x) {
        return p[get(x)];
    }
};