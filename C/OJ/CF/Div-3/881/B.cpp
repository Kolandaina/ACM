#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, a[N];
void slove()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += abs(a[i]);
    }
    int ans = 0, cnt = 0, cntt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            cntt++;
        if (a[i] <= 0)
            cnt++;
        else
        {
            if (cnt > 0)
                ans++;
            if (cnt == cntt && cnt != 0)
                ans--;
            cnt = 0;
            cntt = 0;
        }
    }
    if (cnt > 0 && cnt != cntt)
        ans++;
    cout << sum << " " << ans << endl;
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