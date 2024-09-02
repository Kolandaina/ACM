#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define int long long

using namespace std;
const int N = 15;

char f[N][N];
bool h[N][N], l[N][N], gong[N][N];
bool flag;

int qgong(int x, int y)
{
    if (x <= 3)
    {
        if (y <= 3)
            return 1;
        if (y > 3 && y <= 6)
            return 2;
        if (y > 6 && y <= 9)
            return 3;
    }
    if (x > 3 && x <= 6)
    {
        if (y <= 3)
            return 4;
        if (y > 3 && y <= 6)
            return 5;
        if (y > 6 && y <= 9)
            return 6;
    }
    if (x > 6 && x <= 9)
    {
        if (y <= 3)
            return 7;
        if (y > 3 && y <= 6)
            return 8;
        if (y > 6 && y <= 9)
            return 9;
    }
    return 0;
}
void Print()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
            cout << f[i][j];
        cout << '\n';
    }
    return;
}
void dfs(int x, int y)
{
    if (flag)
        return;
    if (x == 10 && y == 1)
    {
        flag = 1;
        Print();
        return;
    }
    if (f[x][y] == '0')
    {
        for (int i = 1; i <= 9; i++)
        {
            if (!h[x][i] && !l[y][i] && !gong[qgong(x, y)][i])
            {
                h[x][i] = l[y][i] = gong[qgong(x, y)][i] = 1;
                f[x][y] = i + '0';
                if (y < 9)
                    dfs(x, y + 1);
                else
                    dfs(x + 1, 1);
                f[x][y] = '0';
                h[x][i] = l[y][i] = gong[qgong(x, y)][i] = 0;
            }
        }
    }
    else
    {
        if (y < 9)
            dfs(x, y + 1);
        else
            dfs(x + 1, 1);
    }
    return;
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        memset(h, 0, sizeof(h));
        memset(l, 0, sizeof(l));
        memset(gong, 0, sizeof(gong));
        flag = 0;
        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++)
            {
                cin >> f[i][j];
                if (f[i][j] != '0')
                {
                    h[i][f[i][j] - '0'] = true;
                    l[j][f[i][j] - '0'] = true;
                    gong[qgong(i, j)][f[i][j] - '0'] = true;
                }
            }
        dfs(1, 1);
    }
    return 0;
}