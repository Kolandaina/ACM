#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::map<char, int> mp;
    for (auto x : s)
    {
        mp[x]++;
    }
    int maxn = 0ll;
    for (int i = 0; i < 26; i++)
    {
        char ch = 'a' + i;
        maxn = std::max(maxn, mp[ch]);
    }
    int ans = (n % 2);
    if (maxn <= (n / 2))
    {
        std::cout << ans << "\n";
    }
    else
    {
        ans = n - ((n - maxn) << 1);
        std::cout << ans << endl;
    }
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