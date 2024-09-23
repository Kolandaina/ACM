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
    std::vector<int> a(n + 1);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 3 == sum % 3) cnt++;
    }
    if (sum % 3 == 0)
        std::cout << 0 << endl;
    else if (sum % 3 == 2 || cnt != 0)
        std::cout << 1 << endl;
    else if (sum % 3 == 1)
        std::cout << 2 << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) slove();
    return 0;
}