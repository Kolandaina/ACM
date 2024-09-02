#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int a[1000], b[1000];
bool vis[1000], flag = false;
int n;
void dfs(int cnt)
{
    if (cnt > n + 1)
        return;
    if (cnt == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << b[i] << " ";
        }
        flag = true;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (b[cnt - 1] % a[i] == 0 && 3 * a[i] == b[cnt - 1])
        {
            b[cnt] = a[i];
            vis[i] = true;
            dfs(cnt + 1);
            vis[i] = 0;
        }
        else if (a[i] % b[cnt - 1] == 0 && a[i] == 2 * b[cnt - 1])
        {
            b[cnt] = a[i];
            vis[i] = true;
            dfs(cnt + 1);
            vis[i] = 0;
        }
    }
}
inline void slove()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (flag)
            break;
        b[1] = a[i];
        vis[i] = true;
        dfs(2);
        vis[i] = false;
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