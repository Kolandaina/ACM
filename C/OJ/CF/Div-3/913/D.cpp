#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
std::pair<int, int> a[N];
int n;
bool check(int x)
{
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        l = std::max(0ll, l - x);
        r = std::min((long long)1e9, r + x);
        l = std::max(l, a[i].first);
        r = std::min(r, a[i].second);
        if (l > r)
        {
            return false;
        }
    }
    return true;
}
inline void slove()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].first >> a[i].second;
    }
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
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