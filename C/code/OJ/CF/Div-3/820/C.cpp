#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i].first = i;
        a[i].second = s[i] - 'a' + 1;
    }
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