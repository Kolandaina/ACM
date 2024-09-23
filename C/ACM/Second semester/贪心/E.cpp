// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     int n, m;
//     cin >> n >> m;
//     int a[100];
//     a[0] = 1;
//     for (int i = 1; i < 63; i++)
//     {
//         a[i] = 2 * a[i - 1];
//     }
//     int sum = 0, ans = 0;
//     for (int i = 0; i < 63; i++)
//     {
//         if (sum + a[i] <= m)
//         {
//             sum += a[i];
//             ans++;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int ans = 0, a, b;
    cin >> a >> b;
    while ((a | a + 1) <= b)
    {
        a |= a + 1;
    }
    while (a)
    {
        ans += a & 1;
        a >>= 1;
    }
    cout << ans;
    return 0;
}
