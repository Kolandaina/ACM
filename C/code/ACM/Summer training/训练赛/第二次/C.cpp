#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> f(50, vector<int>(50, -1));
    vector<int> x(100), y(100);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> f[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            x[i + j - 1] += (f[i][j] == 1);
            y[i + j - 1] += (f[i][j] == 0);
        }
    }
    for (int i = 1; i * 2 < n + m; i++)
    {
        ans += min(x[i] + x[n + m - i], y[n + m - i] + y[i]);
    }
    cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}