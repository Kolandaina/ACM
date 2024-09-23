#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    if (std::accumulate(a.begin(), a.end(), 0) % 2 == 0)
        std::cout << "YES" << endl;
    else
        std::cout << "NO" << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--)
        slove();
    return 0;
}