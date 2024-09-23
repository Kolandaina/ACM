#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[1000];
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    int ans = a[r] * a[r];
    while (l < r)
    {
        ans += (a[r] - a[l]) * (a[r] - a[l]);
        r--;
        ans += (a[r] - a[l]) * (a[r] - a[l]);
        l++;
    }
    cout << ans << endl;
    return 0;
}