#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int n, m, x, y, p, q;
    std::cin >> n >> m >> x >> y;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) std::cin >> s[i];
    std::cin >> p >> q;
    std::vector<std::pair<int, int>> pre(q);
    for (int i = 0; i < q; i++)
    {
        std::cin >> pre[i].first >> pre[i].second;
        pre[i].second -= 1;
    }
    for (int i = 0; i < p; i++)
    {
        for (auto node : pre)
        {
            if (node.first == 1)
            {
                std::rotate(s[node.second].begin(), s[node.second].end() - 1,
                            s[node.second].end());
            }
            else
            {
                std::string ss;
                for (int i = 0; i < n; i++) ss += s[i][node.second];
                std::rotate(ss.begin(), ss.end() - 1, ss.end());
                for (int i = 0; i < n; i++) s[i][node.second] = ss[i];
            }
        }
    }
    std::cout << s[x - 1][y - 1] << endl;
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