#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    string s, ans;
    cin >> s;
    for (int i = 0; i < 100; i++)
    {
        ans += "Yes";
    }
    if (ans.find(s) == string::npos)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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