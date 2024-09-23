#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        for (int i = 0; i < n; i++)
        {
            int x = 0, y = 0;
            cin >> x >> y;
            if (x == 0)
            {
                y1 = max(y1, y);
                y2 = min(y2, y);
            }
            else
            {
                x1 = max(x1, x);
                x2 = min(x2, x);
            }
        }
        int ans = (x1 - x2 + y1 - y2) * 2;
        cout << ans << endl;
    }
    return 0;
}