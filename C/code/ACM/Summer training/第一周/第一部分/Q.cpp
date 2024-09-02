#include <iostream>
#include <string.h>
using namespace std;
const int N = 1e5;
int p[N];
int vis[N];
int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
int main()
{
    int n, m;
    int v = 1;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            p[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            p[find(a)] = find(b);
        }
        memset(vis, 0, N);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[find(i)] == 0)
            {
                sum++;
                vis[find(i)] = 1;
            }
        }
        cout << "Case " << v++ << ": ";
        cout << sum << endl;
    }
    return 0;
}