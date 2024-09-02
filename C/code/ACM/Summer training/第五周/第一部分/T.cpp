#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
vector<vector<int>> g(N);
int in[N], ans[N];
int n, m;
void topusort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            q.push(i);
        }
    }
    int num = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        ans[num++] = x;
        for (auto e : g[x])
        {
            in[e]--;
            if (!in[e])
            {
                q.push(e);
            }
        }
    }
}
inline void slove()
{
    while (cin >> n >> m && (n != 0 || m != 0))
    {
        memset(in, 0, sizeof(in));
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i <= n; i++)
        {
            g[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            in[y]++;
        }
        topusort();
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
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