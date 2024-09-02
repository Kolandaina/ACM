#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    std::string s;
    std::cin >> s;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (char(i + 'a') != s[0] && char(j + '1') == s[1])
            {
                std::cout << char(i + 'a') << char(j + '1') << endl;
            }
            else if (char(i + 'a') == s[0] && char(j + '1') != s[1])
            {
                std::cout << char(i + 'a') << char(j + '1') << endl;
            }
        }
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