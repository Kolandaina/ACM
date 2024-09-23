#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double a[1000];
    a[0] = 1, a[1] = 1;
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i + 1] = a[i] + a[i - 1];
        ans += 1.0 * a[i + 1] / a[i] * 1.0;
    }
    printf("%.2f", ans);
    return 0;
}