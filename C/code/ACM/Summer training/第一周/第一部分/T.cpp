#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int p[N];
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
    int n;
    while (cin >> n && n != 0)
    {
        int m;
        cin >> m;
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            p[find(x)] = find(y);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == find(i))
            {
                ans++;
            }
        }
        cout << ans - 1 << endl;
    }
    return 0;
}