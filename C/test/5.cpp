#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> ans;
    auto bfs = [&](int s) {
        std::vector<int> dis(n + 1, INT_MAX);
        std::vector<int> pre(n + 1, -1);
        std::queue<int> q;
        dis[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dis[v] == INT_MAX) {
                    dis[v] = dis[u] + 1;
                    pre[v] = u;
                    q.push(v);
                } else if (pre[u] != v) {
                    int len = dis[u] + dis[v] + 1;
                    int curr = u;
                    while (curr != -1) {
                        ans.push_back(curr);
                        curr = pre[curr];
                    }
                    std::reverse(ans.begin(), ans.end());
                    curr = v;
                    while (curr != -1 && std::find(ans.begin(), ans.end(), curr) == ans.end()) {
                        ans.push_back(curr);
                        curr = pre[curr];
                    }
                    return;
                }
            }
        }
    };
    // 仅从节点1开始进行BFS
    bfs(1);
    for (int u : ans) {
        std::cout << u << " ";
    }
    return 0;
}
