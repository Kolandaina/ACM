#include <iostream>
using namespace std;
const int N = 5e5 + 10;
int p[N], vis[N];
int find(int x)
{
    if (p[x] != x)
    {
        int t = p[x];
        p[x] = find(p[x]);
        vis[x] = (vis[x] + vis[t]) % 3;
    }
    return p[x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    while (k--)
    {
        int d, x, y;
        cin >> d >> x >> y;
        if (x > n || y > n || (d == 2 && x == y))
        {
            ans++;
        }
        else
        {
            int fx = find(x);
            int fy = find(y);
            if (fx == fy)
            {
                if (d - 1 != (vis[x] - vis[y] + 3) % 3)
                {
                    ans++;
                }
            }
            else
            {
                p[fx] = fy;
                vis[fx] = (-vis[x] + vis[y] + d - 1) % 3;
            }
        }
    }
    cout << ans << endl;
    return 0;
}