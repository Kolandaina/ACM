#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[5000], b[5000];
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        if (q % 2 == 0)
        {
            a[x] = q;
            x++;
        }
        else
        {
            b[y] = q;
            y++;
        }
    }
    sort(a, a + x);
    sort(b, b + y);
    int m = abs(x - y);
    if (m == 0 || m == 1)
    {
        cout << "0" << endl;
    }
    else
    {
        if (x > y)
        {
            int max1 = 0;
            for (int i = 0; i < m - 1; i++)
            {
                max1 += a[i];
            }
            cout << max1 << endl;
        }
        else
        {
            int max1 = 0;
            for (int i = 0; i < m - 1; i++)
            {
                max1 += b[i];
            }
            cout << max1 << endl;
        }
    }
    return 0;
}