#include <bits/stdc++.h>

#define int long long
#define endl "\n"
const int N = 2e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k;
std::vector<int> g[N];
std::vector<int> in(N + 1);
std::vector<int> res(N + 1);

void dfs(int x)
{
    res[x] = 1;
    for (int i: g[x])
    {
        if (!res[i])
        {
            dfs(i);
        }
    }
}

inline void slove()
{
    std::cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        in[y]++, in[x]++;
    }

    std::queue<int> q;
    std::set<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == k)
        {
            q.push(i);
            res[i] = 1;
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto e: g[x])
        {
            if (res[e])continue;
            in[e]--;
            if (st.count(e))st.erase(e);
            else if (in[e] == k)st.insert(e);
        }
        if (q.empty() && !st.empty())
        {
            for (auto i: st)
            {
                res[i] = 1;
                q.push(i);
            }
            st.clear();
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!res[i])
        {
            dfs(i);
            ans++;
        }
    }
    std::cout << ans << endl;
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