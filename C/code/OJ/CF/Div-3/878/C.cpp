#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0, res = 0;
    vector<int>::iterator it = a.begin();
    for (it = a.begin(); it != a.end(); ++it)
    {
        if (*it <= q) res++;
        else
        {
            if (res >= k) b.push_back(res);
            res = 0;
        }
    }
    if (res >= k) b.push_back(res);
    int len = b.size();
    for (int i = 0; i < len; i++)
    {
        res = b[i] - k + 1;
        ans = ans + (res * (1 + res)) / 2;
    }
    cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}