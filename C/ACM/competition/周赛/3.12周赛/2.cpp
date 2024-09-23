#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, m;
    cin >> n >> m;
    char a[1000000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        char x;
        int y;
        cin >> x >> y;
        int sum = 0;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                sum++;
            }
            if (sum == y)
            {
                cout << i + 1 << endl;
                flag = 1;
                break;
            }
            if (i == n - 1 && flag == 0)
            {
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}