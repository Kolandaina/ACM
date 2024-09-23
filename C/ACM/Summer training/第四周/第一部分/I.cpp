#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 110;
int a[N];
int x[N], y[N];
int ans[N];
inline void slove()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        x[i] = y[i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && y[i] <= y[j] + 1)
            {
                y[i] = y[j] + 1;
            }
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1 + i; j <= n; j++)
        {
            if (a[i] > a[j] && x[i] <= x[j] + 1)
            {
                x[i] = x[j] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] = x[i] + y[i] - 1;
    }
    cout << n - *max_element(ans + 1, ans + n + 1) << endl;
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