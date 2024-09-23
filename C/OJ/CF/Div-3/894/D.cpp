#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, ans;
    cin >> n;
    ans = (sqrt(n * 8 + 1) + 1) / 2;
    cout << ans + n - (ans * (ans - 1)) / 2 << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}