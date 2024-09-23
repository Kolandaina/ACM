#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], b[N];
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        int x = 0, y = 0;
        for (int i = 0; i < m; i++)
        {
            int p;
            cin >> p;
            if (p % 2 == 0)
            {
                a[x] = p;
                x++;
            }
            else
            {
                b[y] = p;
                y++;
            }
        }
        sort(a, a + x);
        sort(b, b + y);
        if (x == 0 || y == 0 || a[0] > b[0])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}