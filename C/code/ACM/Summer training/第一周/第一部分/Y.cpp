#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int T, n, k, l, r, tl, tr, cnt;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        a[n + 1] = a[n] + 2;
        l = a[1], tl = a[1];
        r = 0, tr = 0, cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[i + 1])
                cnt++;
            else
            {
                if (cnt < k || a[i] + 1 != a[i + 1])
                {
                    if (cnt >= k)
                        tr = a[i];
                    if (r - l < tr - tl)
                        l = tl, r = tr;
                    tl = a[i + 1];
                }
                if (cnt >= k)
                    tr = a[i];
                cnt = 1;
            }
        }
        if (!r)
            cout << -1 << "\n";
        else
            cout << l << " " << r << "\n";
    }
    return 0;
}
