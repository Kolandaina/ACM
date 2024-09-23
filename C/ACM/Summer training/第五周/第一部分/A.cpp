#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int n, m;
std::vector<std::vector<int>> g(N + 1);
int a[1010][1010];
inline void slove()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << g[i].size() << " ";
        vector<int> ans;
        for (auto e : g[i])
        {
            ans.push_back(e);
        }
        sort(ans.begin(), ans.end());
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << endl;
    }
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