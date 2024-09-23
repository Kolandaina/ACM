#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
vector<vector<int>> g(N + 1);
int n, m;
int ans[N];
void dfs(int x, int y)
{
    if (ans[x])
    {
        return;
    }
    ans[x] = y;
    for (auto e : g[x])
    {
        dfs(e, y);
    }
}
inline void slove()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!ans[i])
        {
            dfs(i, i);
        }
    }
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        st.insert(ans[i]);
    }
    cout << st.size() << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}