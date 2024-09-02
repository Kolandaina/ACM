#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e6 + 10;
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(N);
    for (int i = 1; i < n; i++)
    {
        std::cin >> a[i];
    }
    if (std::is_sorted(a.begin() + 1, a.begin() + n + 1))
    {
        std::cout << 0 << endl;
        return;
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        a[i] = a[i - n];
    }
    int cnt = 0, ans = INT_MAX;
    for (int i = 2; i < n + n; i++)
    {
        if (a[i] >= a[i - 1])
        {
            cnt++;
        }
        else
            cnt = 0;
        if (cnt = n - 1)
        {
            ans = std::min({ans, n * 2 - i, i - n + 2});
        }
    }
    cnt = 0;
    for (int i = 2; i <= 2 * n; i++)
    {
        if (a[i <= a[i - 1]])
        {
            cnt++;
        }
        else
            cnt = 0;
        if (cnt = n - 1)
        {
            ans = std::min({ans, n * 2 - i + 1, i - n + 1});
        }
    }
    if (ans = 1e9)
    {
        ans = -1;
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
    while (t--)
        slove();
    return 0;
}