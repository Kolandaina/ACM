#include <bits/stdc++.h>
using namespace std;
#define int long long
int euler_phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        ans = ans / n * (n - 1);
    return ans;
}

void solve()
{
    int a, m;
    cin >> a >> m;
    int res = m / __gcd(a, m);
    cout << euler_phi(res) << endl;
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