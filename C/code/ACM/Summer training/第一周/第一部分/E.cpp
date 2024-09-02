#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
const int N = 10;
char f[N][N];
bool flag = false;
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m, t;
int di, dj;
void dfs(int x, int y, int cnt)
{
    if (x > n || y > m || x <= 0 || y <= 0)
        return;
    if (x == di && y == dj && cnt == t)
    {
        flag = true;
        return;
    }

    int temp = t - cnt - abs(x - di) - abs(y - dj);
    if (temp < 0 || temp % 2)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (f[x + d[i][0]][y + d[i][1]] != 'X')
        {
            f[x + d[i][0]][y + d[i][1]] = 'X';
            dfs(x + d[i][0], y + d[i][1], cnt + 1);
            if (flag)
                return;
            f[x + d[i][0]][y + d[i][1]] = '.';
        }
    }
    return;
}
int main()
{
    while (cin >> n >> m >> t && n != 0 && m != 0 && t != 0)
    {
        int wall = 0;
        int sx, sy;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> f[i][j];
                if (f[i][j] == 'S')
                {
                    sx = i, sy = j;
                }
                if (f[i][j] == 'X')
                {
                    wall++;
                }
                if (f[i][j] == 'D')
                {
                    di = i, dj = j;
                }
            }
        }
        if (n * m <= t + wall)
        {
            cout << "NO" << endl;
            continue;
        }
        flag = false;
        f[sx][sy] = 'X';
        dfs(sx, sy, 0);
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}