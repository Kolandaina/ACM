#include <bits/stdc++.h>
void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> v[n + 1];
    std::vector<int> in(n + 1), weight(n + 1, -(1 << 43));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        std::pair<int, int> e;
        e.first = b;
        e.second = c;
        v[a].emplace_back(e);
        in[b]++;
    }
    std::queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int i = 0; i < v[f].size(); i++)
        {
            std::pair<int, int> j = v[f][i];
            in[j.first]--;
            weight[j.first] = std::max(weight[j.first], weight[f] + j.second);
            if (!in[j.first])
                q.push(j.first);
        }
    }
    std::cout << weight[n];
    return;
}
int main()
{
    solve();
    return 0;
}