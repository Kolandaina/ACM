#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, q, maxn = 0;
    cin >> n >> q;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        maxn = max(maxn, x);
        if (!mp[x])
        {
            mp[x] = i;
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        cout << mp[x] << " ";
        for (int i = 1; i <= maxn; i++)
        {
            if (mp[x] > mp[i])
            {
                mp[i]++;
            }
        }
        mp[x] = 1;
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