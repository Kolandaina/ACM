#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main()
{
    int n, a[N], cnt = 0, ans[N];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n / 2; i++)
    {
        ans[++cnt] = a[i + n / 2];
        ans[++cnt] = a[i];
    }
    if (n & 1)
        ans[++cnt] = a[n];
    cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}