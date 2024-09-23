#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
int n, c, d;
int ans[N];
bool check(int x)
{
    int sum = 0;
    sum += (d / (x + 1)) * ans[min(x + 1, n)];
    sum += ans[min(n, (d % (x + 1)))];
    if (sum >= c)
        return 1;
    return 0;
}
bool cmp(int x, int y)
{
    return x > y;
}
void slove()
{
    int maxx = 0;
    cin >> n >> c >> d;
    int l = 0, r = d + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    if (maxx * d < c)
    {
        cout << "Impossible" << endl;
        return;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i - 1] + a[i];
    }
    if (ans[min(n, d)] >= c)
    {
        cout << "Infinity" << endl;
        return;
    }
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << l - 1 << endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}