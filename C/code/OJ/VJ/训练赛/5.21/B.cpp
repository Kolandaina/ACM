#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, a[1002];
    cin >> t;
    while (t--)
    {
        int n, x = 0, y = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i += 2)
        {
            if (a[i] % 2 != 0)
                x++;
        }
        for (int i = 1; i < n; i += 2)
        {
            if (a[i] % 2 != 1)
                y++;
        }

        if (x == y)
            cout << x << endl;
        else
            cout << -1 << endl;
        memset(a, 0, sizeof(a));
    }
    return 0;
}
