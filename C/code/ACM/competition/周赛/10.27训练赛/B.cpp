#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    const int inf = 1e18;
    vector<int> s(n + 1), mx(n + 2, -inf);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int len = n; len >= 1; len--)
    {
        mx[len] = mx[len + 1];
        for (int l = 1, r = l + len - 1; r <= n; l++, r++)
        {
            mx[len] = max(mx[len], s[r] - s[l - 1]);
        }
    }
    mx[0] = max(0ll, mx[1]);
    int t = -inf;
    for (int i = 0; i <= n; i++)
    {
        t = max(t, mx[i] + i * x);
        cout << t << " \n"[i == n];
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