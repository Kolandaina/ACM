#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> m >> n;
    int a[50000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 0, r = n - 1, ans = 0;
    while (l <= r)
    {
        if (a[l] + a[r] <= m)
        {
            l++;
            r--;
            ans++;
        }
        else
        {
            r--;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}