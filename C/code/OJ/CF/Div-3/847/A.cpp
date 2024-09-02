#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const string a = "314159265358979323846264338327";
inline void slove()
{
    string s;
    cin >> s;
    int ans = 0;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] != a[i])
        {
            break;
        }
        ans = i + 1;
    }
    cout << ans << "\n";
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}