#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
inline void slove()
{
    int n;
    int a[N];
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 0)
        {
            a[a[i]] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
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