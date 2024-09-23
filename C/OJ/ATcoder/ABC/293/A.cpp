#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len / 2; i++)
    {
        cout << s[2 * i + 1] << s[2 * i];
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
    {
        slove();
    }
    return 0;
}