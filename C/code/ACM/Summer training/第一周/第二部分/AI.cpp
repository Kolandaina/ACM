#include <iostream>
#include <cstring>
using namespace std;
const int N = 5;
int n, ans;
char f[N][N];
bool fun(int x, int y)
{
    if (f[x][y] == 'X')
    {
        return false;
    }
    for (int i = x - 1; i >= 0; i--)
    {
        if (f[i][y] == '1')
        {
            return false;
        }
        if (f[i][y] == 'X')
        {
            break;
        }
    }
    for (int i = y - 1; i >= 0; i--)
    {
        if (f[x][i] == '1')
        {
            return false;
        }
        if (f[x][i] == 'X')
        {
            break;
        }
    }
    return true;
}
void dfs(int d, int res)
{
    if (d == n * n)
    {
        if (res > ans)
        {
            ans = res;
        }
        return;
    }
    int x = d / n, y = d % n;
    if (fun(x, y))
    {
        f[x][y] = '1';
        dfs(d + 1, res + 1);
        f[x][y] = '.';
    }
    dfs(d + 1, res);
}
int main()
{

    while (cin >> n && n != 0)
    {
        memset(f, 0, sizeof(f));
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> f[i];
        }
        dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}