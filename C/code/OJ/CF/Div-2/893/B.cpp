#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    vector<int> vis(n + 1, 1);
    for (int i = 2; i <= n / 2; i++)
    {
        if (vis[i])
        {
            cout << i << " ";
            vis[i] = 0;
            for (int j = i * 2; j <= n && vis[j]; j = j * 2)
            {
                cout << j << " ";
                vis[j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
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