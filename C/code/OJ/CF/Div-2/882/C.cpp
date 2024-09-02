/***
 * @Author: 羽羽
 * @Date: 2023-07-06 23:45:55
 * @LastEditTime: 2023-07-07 09:47:26
 * @LastEditors: 羽羽
 * @Description:
 * @FilePath: \pythonProjectd:\C\CF\div 2\882\C.cpp
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
int b[N];
void slove()
{
    int n;
    cin >> n;
    set<int> st;
    st.insert(0);
    int res = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        res ^= a[i];
        for (auto it : st)
        {
            ans = max(ans, res ^ it);
        }
        st.insert(res);
    }
    cout << ans << endl;
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