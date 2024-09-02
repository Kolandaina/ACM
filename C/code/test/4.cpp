#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>>e(n + 1);
    vector<array<int, 2>>v;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
        v.push_back({a, b});
    }
    queue<int>q;
    vector<int>vis(n + 1);
    int cnt = 0;
    q.push(1);
    vis[1] = 1;
    cnt = 1;
    while (cnt != k) {
        int u = q.front();
        q.pop();
        for (int v : e[u]) {
            if (vis[v])continue;
            vis[v] = 1;
            q.push(v);
            if (++cnt == k)break;
        }
    }
    for (int i = 1; i <= n; i++) {
        e[i].clear();
    }
    int num = 0;
    for (auto [a, b] : v) {
        if (vis[a] and vis[b]) {
            num++;
            e[a].push_back(b);
            e[b].push_back(a);
        }
    }
    array<vector<int>, 2>g;
    auto dfs = [&](auto &&self, int u, int fa, int col)->void{
        g[col].push_back(u);
        for (int v : e[u]) {
            if (v == fa)continue;
            self(self, v, u, col ^ 1);
        }
    };
    // cout<<num<<"\n";
    if (num == k - 1) {
        dfs(dfs, 1, 0, 0);
        int u = 0;
        if (g[u].size() < g[u ^ 1].size())u ^= 1;
        cout << "1" << "\n";
        int cnt = 0;
        for (auto x : g[u]) {
            cnt++;
            if (cnt > (k + 1) / 2)break;
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    fill(vis.begin(), vis.end(), 0);
    vector<int>stk, ans; int top = 0;
    auto dfs1 = [&](auto self, int u, int fa)->void{
        stk.push_back(u);
        vis[u] = 1;
        for (int v : e[u]) {
            if (v == fa)continue;
            if (vis[v]) {
                while (stk.back() != v) {
                    ans.push_back(stk.back());
                    stk.pop_back();
                }
                ans.push_back(v);
                cout << "2" << "\n";
                cout << ans.size() << "\n";
                for (auto c : ans) {
                    cout << c << " ";
                }
                cout << "\n";
                exit(0);
            }
            self(self, v, u);
        }
        stk.pop_back();
    };
    dfs1(dfs1, 1, 0);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
