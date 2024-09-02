#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> mp(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x]++, mp[y]--;
    }
    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        mp[i] += mp[i - 1];
        maxn = max(maxn, mp[i]);
    }
    cout << (maxn - 1) / k + 1 << endl;
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