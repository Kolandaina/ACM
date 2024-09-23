#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e4;
int x[N], y[N];
bool vis[N];
double ans, d[N], minn;
int n, t;
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void slove()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        d[i] = 1e10 * 1.0;
    }
    d[1] = 0.0;
    vis[1] = true;
    for (int i = 1; i <= n; i++)
    {
        t = 1, minn = 1e9 * 1.0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && d[j] < minn)
            {
                minn = d[j];
                t = j;
            }
        }
        vis[t] = true;
        ans += d[t];
        for (int j = 1; j <= n; j++)
        {
            d[j] = min(d[j], distance(x[t], y[t], x[j], y[j]));
        }
    }
    printf("%.2lf", ans);
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}