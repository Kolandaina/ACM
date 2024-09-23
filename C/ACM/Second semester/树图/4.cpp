#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int mod = 80112002;
const int maxn = 5005;
const int maxm = 500005;

vector<int> g[maxn];
int in_degree[maxn];
int dp[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        in_degree[a]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            dp[v] = max(dp[v], dp[u] + 1) % mod;
            in_degree[v]--;
            if (in_degree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans % mod << endl;
    return 0;
}
