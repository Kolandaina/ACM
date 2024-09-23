#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
inline void slove()
{
    int n;
    std::cin >> n;
    int ans = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    auto check = [&]() {
        int cnt[100] = {0};
        for (auto i : a)
        {
            for (int j = 0; j < 36; j++)
                if ((j * (i < 10LL ? 10LL : 28LL) + i) % 36 == 0) ans += cnt[j];
            cnt[i % 36]++;
        }
    };
    check();
    std::reverse(a.begin(), a.end());
    check();
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