#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        c[i] = a[i] - b[i];
    int maxn = *max_element(c.begin(), c.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == maxn)
            ans++;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == maxn)
            cout << i + 1 << " ";
    }
    cout << endl;
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