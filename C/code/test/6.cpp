#include <bits/stdc++.h>
using namespace std;
struct ee
{
    int first, second;
} a[121], b[121];
bool f[121];
int n, p = 1, len = 1, ans;
bool mycmp(ee q, ee w) { return q.first < w.first; }
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; i++) cin >> b[i].first >> b[i].second;
    sort(a + 1, a + 1 + n, mycmp);
    sort(b + 1, b + 1 + n, mycmp);
    for (int i = n; i >= 1; i--)
    {
        int maxx = 10000, t = 0;
        for (int j = n; j >= 1; j--)
        {
            if (a[i].first > b[j].first) break;
            if (!f[j] && a[i].second < b[j].second)
            {
                if (b[j].second <= maxx) maxx = b[j].second, t = j;
            }
        }
        if (t != 0) f[t] = 1, ans++;
    }
    cout << ans;
    return 0;
}
