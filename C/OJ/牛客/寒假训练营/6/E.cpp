#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    std::string s1, s;
    std::cin >> s1 >> s;
    int n = std::stoi(s1.erase(0, 2));
    int p = 0, r = 0;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'P') p++;
        if (s[i] == 'R') r++;
        if (p == n / 2 + 1)
        {
            std::cout << "yukari!" << endl;
            std::cout << i + 1 << endl;
            return;
        }
        if (r == n / 2 + 1)
        {
            std::cout << "kou!" << endl;
            std::cout << i + 1 << endl;
            return;
        }
    }
    std::cout << "to be continued." << endl;
    std::cout << len << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}