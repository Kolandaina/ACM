#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        int ans[100][100];
        memset(ans, 0, sizeof(ans));
        int cnt = 0;
        cin >> n >> m >> a >> b;
        if (n * a != m * b)
        {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < a; j++)
            {
                ans[i][cnt++] = 1;
                cnt %= m;
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}