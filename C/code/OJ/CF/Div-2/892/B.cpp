#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    vector<int> a[n];
    int minn = 1e15;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end());
        minn = min(minn, a[i][0]);
        res += a[i][1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, res - a[i][1] + minn);
    }
    cout << ans << endl;
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