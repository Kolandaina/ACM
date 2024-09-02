#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    map<int, int> mp;
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if ((it.first | a[i]) == it.first)
            {
                st.insert(i);
            }
        }
    }
    int ans = 0;
    for (auto it : st)
        ans += b[it];
    cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}