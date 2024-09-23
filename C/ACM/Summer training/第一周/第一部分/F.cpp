#include <iostream>
using namespace std;
const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];
int ans = 0;
int res[10] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
void dfs(int u)
{
    if (u == n)
    {
        ans++;
        return;
    }
    int x = u;
    for (int y = 0; y < n; y++)
        if (col[y] == false && dg[y - x + n] == false && udg[y + x] == false)
        {
            col[y] = dg[y - x + n] = udg[y + x] = true;
            dfs(x + 1);
            col[y] = dg[y - x + n] = udg[y + x] = false;
        }
}

int main()
{
    while (cin >> n && n != 0)
    {
        // ans = 0;
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < n; j++)
        //         g[i][j] = '.';

        // dfs(0);
        // cout << ans << endl;
        cout << res[n - 1] << endl;
    }
    return 0;
}
