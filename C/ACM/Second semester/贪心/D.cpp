#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[100010];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans[10010];
    for (int i = 0; i < m; i++)
    {
        ans[i] = a[i];
    }
    int t = m;
    int cnt = 0;
    while (t < n + m)
    {
        for (int i = 0; i < m; i++)
        {
            ans[i]--;
            if (ans[i] == 0)
            {
                ans[i] = a[t];
                t++;
            }
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}