#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, ans;
int a[N], b[N], c[N], s[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int cnt = upper_bound(c + 1, c + 1 + n, b[i]) - c;
        s[i] = n - cnt + 1;
    }
    for (int i = n; i >= 1; --i)
        s[i] += s[i + 1];
    for (int i = 1; i <= n; i++)
        ans += s[upper_bound(b + 1, b + 1 + n, a[i]) - b];

    cout << ans << endl;
    return;
}
int main()
{
    solve();
    return 0;
}