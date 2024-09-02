#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
int a[N];
inline void slove()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0, res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += a[i];
        if (res <= 0)
            res = 0;
        ans = max(ans, res);
    }
    if (*max_element(a + 1, a + n + 1) < 0)
        cout << *max_element(a + 1, a + n + 1) << endl;
    else
        cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}