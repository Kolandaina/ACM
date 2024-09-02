/***
 * @Author: your name
 * @Date: 2023-07-06 22:52:08
 * @LastEditTime: 2023-07-06 22:53:35
 * @LastEditors: 羽羽
 * @Description:
 * @FilePath: \pythonProjectd:\C\CF\div 2\882\B.cpp
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
inline void slove()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    int res = a[0];
    for (int i = 1; i <= n; i++)
    {
        if (res == 0)
        {
            ans++;
            res = a[i];
            continue;
        }
        else
        {
            res &= a[i];
        }
    }
    if (ans)
        cout << ans << endl;
    else
        cout << 1 << endl;
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