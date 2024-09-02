#include <iostream>
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
    int n, m;
    int px, py, tx, ty;
    while (cin >> n >> m)
    {
        if (m == 0 && n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            p[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int w;
            cin >> w;
            cin >> tx;
            px = find(tx);
            for (int j = 1; j < w; j++)
            {
                cin >> ty;
                py = find(ty);
                if (py < px)
                {
                    p[px] = py;
                    px = py;
                }
                else
                {
                    p[py] = px;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (find(i) == 0)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}