#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
std::vector<int> f[N], st[N];
int cnt, sum, n, m;
bool flag;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int x, int y)
{
    st[x][y] = true;
    if (f[x][y] > 1) flag = true;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && f[xx][yy] &&
            !st[xx][yy])
        {
            if (f[xx][yy] > 1) flag = true;
            dfs(xx, yy);
        }
    }
}
inline void slove()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        f[i].push_back(0);
        st[i].push_back(0);
        for (int j = 1; j <= m; j++)
        {
            char c;
            std::cin >> c;
            f[i].push_back(c - '0');
            st[i].push_back(0);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (f[i][j] && !st[i][j])
            {
                flag = false;
                sum++;
                dfs(i, j);
                if (flag) cnt++;
            }
        }
    std::cout << sum << " " << cnt;
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