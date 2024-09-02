#include <bits/stdc++.h>
using namespace std;
#define int long long
int div(int x, int res, int b)
{
    int k = x / b;
    if (k % res == 0)
    {
        return x - ((k / res) - 1) * b - x % b - 1;
    }
    return x - (k / res) * b;
}
void solve()
{
    int a, b, q;
    cin >> a >> b >> q;
    if (a > b)
    {
        swap(a, b);
    }
    int res = a / __gcd(a, b);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << div(r, res, b) - div(l - 1, res, b) << " ";
    }
    cout << endl;
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