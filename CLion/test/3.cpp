#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

using ldb = long double;

#define int i64

using vi = vector<int>;
using pii = pair<int, int>;

const int inf = LLONG_MAX;
const int N = 1e4;

vi vis(N);
vector<vector<pii>> e(N);

vector<pii> path;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edge(m);
    vi line;
    for (auto &[x, y, z]: edge) cin >> x >> y >> z, line.push_back(z);
    sort(line.begin(), line.end());
    line.resize(unique(line.begin(), line.end()) - line.begin());
    vector<set<pii>> e(n + line.size() + 1);
    for (auto &[x, y, z]: edge) {
        z = lower_bound(line.begin(), line.end(), z) - line.begin() + n + 1;
        e[x].emplace(z, 1);
        e[y].emplace(z, 1);
        e[z].emplace(x, 0);
        e[z].emplace(y, 0);
    }
    int sta, ed;
    cin >> sta >> ed;
    vi dis(n + line.size() + 1, inf);
    dis[sta] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, sta);
    vi vis(n + line.size() + 1);
    while (not q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w]: e[u]) {
            if (vis[v]) continue;
            if (dis[v] > d + w) {
                dis[v] = d + w;
                q.emplace(dis[v], v);
            }
        }
    }
    cout << dis[ed] << "\n";
    return;
}

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int TC = 1;
    for (cin >> TC; TC; TC--)
        solve();
    return 0;
}