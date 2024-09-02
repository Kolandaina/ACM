#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        int a[10000];
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        int cnt = 0, ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[i] == 0)
            {
                cnt++;
            }
            else if (a[i] == 1)
            {
                cnt = 0;
            }
            ans = max(cnt, ans);
        }
        cout << ans << endl;
    }
    return 0;
}