#include <bits/stdc++.h>
using namespace std;
#define int long long
int vis[100] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096,
                8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
signed main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int l, r;
        cin >> l >> r;
        if (l * 2 > r)
        {
            cout << 1 << " " << r - l + 1 << endl;
            continue;
        }
        int ans = 1;
        for (int i = 0; i < r; i++)
        {
            if (l * vis[i] <= r)
            {
                ans++;
            }
            else
                break;
        }
        int res = 0;
        res = r / vis[ans - 2] - l + 1 + max(0ll, (r / (vis[ans - 2] / 2 * 3)) - (l - 1)) * (ans - 1);
        cout << ans << " " << res << endl;
    }
    return 0;
}