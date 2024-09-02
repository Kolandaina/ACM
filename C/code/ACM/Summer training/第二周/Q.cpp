#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m;
    int sum = 0;
    cin >> n >> m;
    int j = 0, o = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        if (x % 2 == 0)
        {
            o++;
        }
        else
        {
            j++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x)
        {
            if (y % 2 == 0)
            {
                sum += y * j;
            }
            else
            {
                sum += y * j;
                o += j;
                j = 0;
            }
        }
        else
        {
            if (y % 2 == 0)
            {
                sum += y * o;
            }
            else
            {
                sum += y * o;
                j += o;
                o = 0;
            }
        }
        cout << sum << endl;
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}