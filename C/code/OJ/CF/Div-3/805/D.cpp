#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
inline void slove()
{
    int k, ans = 0;
    string s;
    cin >> s >> k;
    int n = s.length();
    vector<pair<int, int>> v, f;
    for (int i = 0; i < n; i++)
    {
        f.push_back({i, s[i] - 'a' + 1});
    }
    sort(f.begin(), f.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
    for (auto i : f)
    {
        if (ans + i.second <= k)
        {
            ans += i.second;
            v.push_back({i.first, i.second});
        }
        else
            break;
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first < b.first; });
    for (auto e : v)
    {
        cout << char(e.second + 'a' - 1);
    }
    cout << endl;
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