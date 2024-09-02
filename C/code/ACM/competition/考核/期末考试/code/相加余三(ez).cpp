#include <bits/stdc++.h>

#define int long long

signed main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i : a) std::cin >> i;

    int res = 0, ans = 0;

    for (int i = 0; i + 1 < n; i += 2)
    {
        ans += (a[i] + a[i + 1]) % 3;
    }
    res = std::max(res, ans);

    ans = 0;
    for (int i = n - 1; i - 1 >= 0; i -= 2)
    {
        ans += (a[i] + a[i - 1]) % 3;
    }
    res = std::max(res, ans);

    ans = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        ans += (a[i] + a[j]) % 3;
    }
    res = std::max(res, ans);

    std::cout << res;

    return 0;
}