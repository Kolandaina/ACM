#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), b(m + 1);
    int maxa, max1, mina, min1;
    int maxb, max2, minb, min2;
    max1 = maxa = maxb = max2 = -1e5;
    min1 = mina = minb = min2 = 1e5;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        maxa = std::max(a[i], maxa + a[i]);
        max1 = std::max(max1, maxa);
        mina = std::min(a[i], mina + a[i]);
        min1 = std::min(min1, mina);
    }
    for (int i = 1; i <= m; i++)
    {
        std::cin >> b[i];
        maxb = std::max(b[i], maxb + b[i]);
        max2 = std::max(maxb, max2);
        minb = std::min(b[i], minb + b[i]);
        min2 = std::min(min2, minb);
    }
    std::cout << std::max({max1 * max2, max1 * min2, min1 * max2, min1 * min2});
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