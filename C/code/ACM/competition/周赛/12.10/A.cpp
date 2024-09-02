#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if (s1.size() < s2.size())
    {
        std::swap(s1, s2);
    }
    s1 += s1;
    if (s1.find(s2) != std::string::npos)
    {
        std::cout << "YES" << endl;
    }
    else
    {
        std::cout << "NO" << endl;
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