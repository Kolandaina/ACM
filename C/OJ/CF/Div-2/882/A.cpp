#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N];
int b[N];
void slove()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        b[i] = abs(a[i] - a[i - 1]);
    }
    sort(b, b + n);
    int ans = 0;
    for (int i = 0; i < n - k + 1; i++)
    {
        ans += b[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}