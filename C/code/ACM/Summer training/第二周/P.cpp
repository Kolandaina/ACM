#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
bool vis[N];
int main()
{
    int n;
    cin >> n;
    int maxn = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        maxn = max(maxn, a);
        vis[a] = true;
    }
    int ans = 0;
    for (int d = 1; d <= maxn; d++)
    {
        if (vis[d])
            continue;
        int res = 0;
        for (int i = d + d; i <= maxn; i += d)
        {
            if (vis[i])
            {
                res = __gcd(res, i / d);
            }
        }
        if (res == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}