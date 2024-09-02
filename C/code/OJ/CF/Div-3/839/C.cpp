#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int k, n;
    cin >> k >> n;
    int ans = 0;
    for (int i = 1; k && i < n; i++, k--)
    {
        cout<< ans + i << " ";
        ans++;
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}