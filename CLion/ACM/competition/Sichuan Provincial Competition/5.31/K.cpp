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
    std::vector<std::pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    std::sort(a.begin() + 1, a.end(), [](std::pair<int, int> a, std::pair<int, int> b) { return a.first < b.first; });
    int ans = n;
    for(int i=n;i>n/2;i--)
    {

    }
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