#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, k;
    cin >> n >> k;
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (mp.find(x) == mp.end())
            mp[x] = {i, i};
        else
            mp[x].second = i;
    }
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (mp.find(x) == mp.end() || mp.find(y) == mp.end())
            cout << "NO" << endl;
        else if (mp[y].second < mp[x].first)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
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