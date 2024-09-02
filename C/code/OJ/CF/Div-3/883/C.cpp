#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node
{
    int num;
    int h;
    int x;
} f[N];
int a[N];
void slove()
{
    int n, m, h;
    cin >> n >> m >> h;
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[j];
        }
        sort(a, a + m);
        for (int j = 0; j < m; j++)
        {
            if (f[i].x + a[j] <= h)
            {
                f[i].h *= 2;
                f[i].h += a[j];
                f[i].x += a[j];
                f[i].num++;
            }
            else
                break;
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        cout << f[i].num << " " << f[i].h << " " << f[i].x << endl;
    }
    for (int i = 1; i < n; i++)
    {
        if (f[i].num > f[0].num)
        {
            ans++;
        }
        else if (f[i].num == f[0].num && f[i].h < f[0].h)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}