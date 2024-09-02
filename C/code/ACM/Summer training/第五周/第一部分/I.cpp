#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int n, h, r;
int p[N];
struct node
{
    int x, y, z;
} f[N];
double dis(double xa, double ya, double za, double xb, double yb, double zb)
{
    return (double)(sqrt((double)(xa - xb) * (xa - xb) + (double)(ya - yb) * (ya - yb) + (double)(za - zb) * (za - zb)));
}
int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
inline void slove()
{
    cin >> n >> h >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].x >> f[i].y >> f[i].z;
    }
    for (int i = 0; i <= n + 1; i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i].z - r <= 0)
        {
            if (find(i) != find(0))
            {
                p[find(i)] = find(0);
            }
        }
        if (f[i].z + r >= h)
        {
            if (find(i) != find(n + 1))
            {
                p[find(i)] = find(n + 1);
            }
        }
        for (int j = i + 1; j <= n; j++)
        {
            if (dis(f[i].x, f[i].y, f[i].z, f[j].x, f[j].y, f[j].z) - 2 * r <= 0)
            {
                if (find(i) != find(j))
                {
                    p[find(i)] = find(j);
                }
            }
        }
    }
    if (find(0) == find(n + 1))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}