#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    std::string s;
    std::cin >> s;
    int n;
    std::cin >> n;
    while (n--)
    {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        std::string c, d;
        std::cin >> c >> d;
        std::string temp = s.substr(a, b - a + 1);
        std::string check = c + d;
        s.erase(a, b - a + 1);
        int pos = s.find(check);
        if (pos == -1)
            s += temp;
        else
        {
            std::string t =
                s.substr(0, pos + c.size()) + temp + s.substr(pos + c.size());
            s = t;
        }
    }
    std::cout << s;
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