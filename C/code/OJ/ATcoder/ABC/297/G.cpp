#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 5;
int n, l, r;
int p[N];
int sg(int x)
{
    x %= (l + r);
    return x / l;
}
inline void slove()
{
    cin >> n >> l >> r;
    int res = 0;
    for (int i = 1, c; i <= n; i++)
    {
        cin >> c;
        res ^= sg(c);
    }
    if (res)
        puts("First");
    else
        puts("Second");
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}
