#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    vector<int> wt(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            int x;  
            cin >> x;
            wt[x - 1] += j;
        }
    }
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    sort(ans.begin(), ans.end(), [&](int x, int y)
         { return wt[x] < wt[y]; });
    for (int x : ans)
        cout << x + 1 << ' ';
    cout << '\n';
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