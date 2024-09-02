#include <bits/stdc++.h>
using namespace std;
inline void solve()
{
    long long n;
    cin >> n;
    if (n == 1)
    {
        cout << "NO" << '\n';
        return;
    }
    if (double(sqrt(n)) != int(sqrt(n)))
    {
        cout << "NO" << '\n';
        return;
    }
    bool flag = false;
    for (int i = 2; i <= sqrt(n) / i; i++)
    {
        if (n % i == 0)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';
    }
}
int main()
{

    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}