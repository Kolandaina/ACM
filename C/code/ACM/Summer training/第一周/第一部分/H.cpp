#include <iostream>
using namespace std;
char f[25][25];
int tx, ty, w, h;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dfs(int x, int y)
{
    int ans = 1;
    f[x][y] = '#';
    for (int i = 0; i <= 3; i++)
    {
        int ttx = x + dx[i], tty = y + dy[i];
        if (ttx >= 1 && tty >= 1 && ttx <= w && tty <= h && f[ttx][tty] == '.')
        {
            ans += dfs(ttx, tty);
        }
    }
    return ans;
}
int main()
{
    cin >> h >> w;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            cin >> f[i][j];
            if (f[i][j] == '@')
            {
                tx = i, ty = j;
            }
        }
    }
    int res = dfs(tx, ty);
    cout << res << endl;
    return 0;
}