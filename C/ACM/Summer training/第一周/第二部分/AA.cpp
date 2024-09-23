#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, m, ans;
int a[N];
struct node
{
    int a, b, c;
} f[N];
void slove()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < m; i++)
    {
        cin >> f[i].a >> f[i].b >> f[i].c;
    }
    for (int i = 0; i < m; i++)
    {
        int pos = lower_bound(a, a + n, f[i].b) - a;
        int x = pow(f[i].b - a[pos], 2) - 4 * f[i].c * f[i].a;
        int y = pow(f[i].b - a[pos - 1], 2) - 4 * f[i].a * f[i].c;
        if (x < 0 && pos >= 0 && pos < n)
        {
            cout << "YES" << endl;
            cout << a[pos] << endl;
            continue;
        }
        if (y < 0 && pos - 1 >= 0 && pos - 1 < n)
        {
            cout << "YES" << endl;
            cout << a[pos - 1] << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}