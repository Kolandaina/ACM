#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y, z, g;
};
struct node1
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        return s1.z < s2.z;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        node f[1010];
        int a[1010];
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            cin >> f[i].x >> f[i].y;
            f[i].z = abs(f[i].x - f[i].y);
        }
        sort(f + 1, f + n + 1, node1());
        int o = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = f[i].x; j <= f[i].y; j++)
            {
                if (f[j].g == 0)
                {
                    a[o++] = j;
                    f[j].g = j;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << f[i].x << " " << f[i].y << " " << a[i] << endl;
        }
    }
    return 0;
}