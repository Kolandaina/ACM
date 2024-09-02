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
    int ans = 0, cnt = 0, temp = a[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != temp)
        {
            temp = a[i - 1];
            ans++;
            cnt = 0;
        }
        else
            cnt++;
    }
    std::cout << ans + cnt << endl;
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