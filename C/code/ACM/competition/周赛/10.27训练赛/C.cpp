#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    vector<int> a(n + 10, 0), b(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int j = n; j >= 1; j--)
    {
        a[j] = a[j + 1] + a[j];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i] = b[i] + b[i - 1];
    }
    int mn = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (max(a[i + 1], b[i - 1]) < mn)
        {
            mn = max(a[i + 1], b[i - 1]);
        }
    }
    cout << mn << endl;
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