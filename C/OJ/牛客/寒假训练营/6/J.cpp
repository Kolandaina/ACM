#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
template <class T1, class T2>
std::istream &operator>>(std::istream &cin, std::pair<T1, T2> &a)
{
    return cin >> a.first >> a.second;
}
template <class T1, class T2>
std::ostream &operator<<(std::ostream &cout, const std::pair<T1, T2> &a)
{
    return cout << a.first << ' ' << a.second;
}
template <class T1>
std::istream &operator>>(std::istream &cin, std::vector<T1> &a)
{
    for (auto &x : a) cin >> x;
    return cin;
}
template <class T1>
std::ostream &operator<<(std::ostream &cout, const std::vector<T1> &a)
{
    int n = a.size();
    if (!n) return cout;
    cout << a[0];
    for (int i = 1; i < n; i++) cout << ' ' << a[i];
    return cout;
}
inline void slove()
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = ' ' + s;
    std::vector<std::vector<int>> g(n + 3), k(n + 3);
    std::vector<int> f;
    for (int i = 2; i <= n; ++i)
    {
        int x;
        std::cin >> x;
        g[x].push_back(i);
    }
    auto dfs = [&](auto self, int u) -> void {
        if (s[u] == 'W' && f.size()) k[f.back()].push_back(u);
        if (s[u] == 'R') f.push_back(u);
        for (auto v : g[u]) self(self, v);
        if (s[u] == 'R') f.pop_back();
    };
    dfs(dfs, 1);
    std::vector<int> ans(n + 3);
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'R')
        {
            k[i].push_back(i);
            if (k[i].size() == 1)
            {
                std::cout << -1 << endl;
                return;
            }
            for (auto v : k[i]) ans[v] = 1;
            if (k[i].size() % 3 == 1) ans[k[i][0]] = 2;
            if (k[i].size() % 3 == 1)
            {
                ans[k[i][0]] = 2;
                ans[k[i][1]] = 2;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        std::cout << (ans[i] == 0 ? 1 : ans[i]);
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}