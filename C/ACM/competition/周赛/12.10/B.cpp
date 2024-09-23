#include <bits/stdc++.h>
#define int long long
#define endl "\n"
std::map<int, int> mp;
int dfs(int x)
{
    if (mp[x])
        return mp[x];
    else
        return mp[x] = dfs(x / 2) + dfs(x / 3);
}
inline void slove()
{
    int n;
    std::cin >> n;
    mp[0] = 1;
    std::cout << dfs(n) << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        slove();
    return 0;
}