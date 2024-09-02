#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
void solve()
{
    int n, ok = 1, flag = 1;
    int a[N];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] > a[i + 1])
            flag = 0;
        if (!flag && a[i] < a[i + 1])
            ok = 0;
    }
    if (!ok)
        puts("NO");
    else
        puts("YES");
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