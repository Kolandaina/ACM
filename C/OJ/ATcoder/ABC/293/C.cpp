#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 15;
int f[N][N];
int fun[N * N];
int n, m;
int ans, top;
inline void dfs(int x, int y)
{
    for (int i = 1; i <= top; i++)
    {
        if (fun[i] == f[x][y])
        {
            return;
        }
    }
    fun[++top] = f[x][y];
    if (x == n && y == m)
    {
        ans++;
        top--;
        return;
    }
    if (x < n)
        dfs(x + 1, y);
    if (y < m)
        dfs(x, y + 1);
    top--;
}
inline void slove()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> f[i][j];
        }
    }
    dfs(1, 1);
    cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}