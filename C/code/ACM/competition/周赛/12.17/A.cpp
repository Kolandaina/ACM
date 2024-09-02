#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    std::cin >> n;
    int l = 1, r = 1e15;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (mid * log10(mid) >= n)
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        slove();
    return 0;
}