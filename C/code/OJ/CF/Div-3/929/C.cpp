#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int a, b, x;
    std::cin >> a >> b >> x;
    std::set<int> q;
    int y = x;
    while (y % b == 0)
    {
        q.insert(y);
        y /= b;
    }
    q.insert(y);
    while (x % a == 0)
    {
        x /= a;
        y = x;
        while (y % b == 0)
        {
            q.insert(y);
            y /= b;
        }
        q.insert(y);
    }
    std::cout << q.size() << '\n';
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