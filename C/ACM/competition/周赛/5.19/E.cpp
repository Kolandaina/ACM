#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i] >> b[i];
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i] * i - (n - i - 1) * a[i];
        ans += b[i] * i - (n - i - 1) * b[i];
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