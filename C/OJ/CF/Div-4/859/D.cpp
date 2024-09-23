#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
inline void slove()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int t = a[r] - a[l - 1] + (r - l + 1) * x;
        if ((a[n] + t) % 2 == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
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