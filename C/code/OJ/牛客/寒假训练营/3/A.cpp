#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
inline void slove()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if (std::tolower(s1[0]) == std::tolower(s2[0]))
        std::cout << "Yes" << endl;
    else
        std::cout << "No" << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) slove();
    return 0;
}