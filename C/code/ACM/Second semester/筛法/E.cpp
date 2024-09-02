#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int a[10000];
    int max_i;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        max_i = max(max_i, a[i]);
    }
    int yp = 0, ans = 0;
    for (int i = 2; i <= max_i; i++)
    {
        int xp = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[j] % i == 0)
            {
                xp++;
            }
        }
        if (xp > yp)
        {
            yp = xp;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}