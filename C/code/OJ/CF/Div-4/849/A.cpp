#include <bits/stdc++.h>
using namespace std;
#define int long long
const string s = "codeforces";
#define endl "\n"
inline void solve()
{
    string s1;
    cin >> s1;
    if (s.find(s1) >= 0 && s.find(s1) <= 11)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}