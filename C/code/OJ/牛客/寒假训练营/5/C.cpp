#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    a[0] = a[n + 1] = INF;
    int ans = 0, s = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        s = std::min(a[i], a[i - 1]);
        ans += s;
        a[i] -= s;
    }
    std::cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}