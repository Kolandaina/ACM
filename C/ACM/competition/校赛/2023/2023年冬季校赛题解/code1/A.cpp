#include  <bits/stdc++.h>

using INT = long long;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> g(n * 5 + 1);

    auto get = [&](int deep, int v) {
        return n * (deep - 1) + v;
    };

    while (m--) {
        int x, y, z;
        std::cin >> x >> y >> z;
        g[get(1, x)].emplace_back(get(1, y), z), g[get(1, y)].emplace_back(get(1, x), z);
        g[get(2, x)].emplace_back(get(2, y), z), g[get(2, y)].emplace_back(get(2, x), z);
        g[get(3, x)].emplace_back(get(3, y), z), g[get(3, y)].emplace_back(get(3, x), z);
        g[get(1, x)].emplace_back(get(2, y), 0), g[get(1, y)].emplace_back(get(2, x), 0);
        g[get(2, x)].emplace_back(get(3, y), 2 * z), g[get(2, y)].emplace_back(get(3, x), 2 * z);
    }

    std::vector<INT> dist(5 * n + 1, LLONG_MAX);
    std::vector<bool> vis(5 * n + 1);

    using PII = std::pair<int, int>;

    std::priority_queue<PII, std::vector<PII>, std::greater<>> q;

    dist[1] = 0;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto [dis, fa] = q.top();
        q.pop();
        if (vis[fa]) continue;
        vis[fa] = true;

        for (auto [e, w]: g[fa]) {
            if (dist[e] > dist[fa] + w) {
                dist[e] = dist[fa] + w;
                q.emplace(dist[e], e);
            }
        }
    }

    INT res = LLONG_MAX;

    for (int i = get(3, 1); i <= get(3, n); i++) {
        res = std::min(res, dist[i]);
    }

    for (auto i: g[1]) {
        if (i.first <= n)
            res = std::min(res, dist[i.first]);
    }

    std::cout << res;

}