#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int ans = 0;
    int res1 = 0, res2 = 0;
    for (auto x : mp)
    {
        if (x.second > 1)
        {
            ans++;
            if (!res1)
                res1 = x.first;
            res2 = x.first;
        }
    }
    if (ans < 2)
    {
        cout << -1 << endl;
        return;
    }
    int x = 1, y = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == res1 && x == 1)
        {
            cout << 3 << " ";
            x++;
        }
        else if (a[i] == res2 && y == 1)
        {
            cout << 2 << " ";
            y++;
        }
        else if (a[i] == res1 && x == 2)
        {
            cout << 1 << " ";
            x++;
        }
        else if (a[i] == res2 && y == 2)
        {
            cout << 1 << " ";
            y++;
        }
        else
        {
            cout << 1 << " ";
        }
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