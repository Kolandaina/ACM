#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    int n, m;
    std::cin >> n >> m;
    std::string ans;
    while (n--)
    {
        if (m > 10)
        {
            ans += '9';
            m -= 9;
        }
        else
        {
            ans += char(m + '0');
            m = 0;
        }
    }
    std::cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--)
        slove();
    return 0;
}