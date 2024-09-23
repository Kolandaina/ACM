#include <iostream>
#include <cstring>
using namespace std;
const int N = 1000;
int q, p, k;
struct node
{
    int x, y;
} f[N];
bool fun[N][N];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool flag = false;
bool judge(int x, int y)
{

    if (x < 1 || y < 1 || x > p || y > q)
    {
        return false;
    }
    if (fun[x][y] || flag)
    {
        return false;
    }
    return true;
}
void dfs(int x, int y, int deep)
{
    if (deep == p * q)
    {
        for (int i = 1; i <= deep; i++)
        {
            cout << char(f[i].y - 1 + 'A') << f[i].x;
        }
        cout << endl
             << endl;
        flag = true;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int sx = x + dx[i];
        int sy = y + dy[i];
        if (judge(sx, sy))
        {
            f[deep + 1].x = sx;
            f[deep + 1].y = sy;
            fun[sx][sy] = true;
            dfs(sx, sy, deep + 1);
            fun[sx][sy] = 0;
        }
    }
}
void slove()
{
    cin >> p >> q;
    memset(fun, false, sizeof(fun));
    memset(f, 0, sizeof(f));
    flag = false;
    cout << "Scenario #" << ++k << ":" << endl;
    f[1].x = 1, f[1].y = 1;
    fun[1][1] = true;
    dfs(1, 1, 1);
    if (flag == false)
    {
        cout << "impossible" << endl
             << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        slove();
    }
    return 0;
}
/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef struct Path
{
    int y;
    int x;
} Path;
Path path[1001];
bool isFound = false;
int p, q;
bool mark[51][51];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool isInMap(int ny, int nx)
{
    if (nx >= 1 && nx <= q && ny >= 1 && ny <= p)
    {
        return 1;
    }
    return 0;
}
void dfs(int y, int x, int step)
{
    if (step == p * q)
    {
        for (int i = 1; i <= step; i++)
        {
            cout << char(path[i].x + 'A' - 1) << path[i].y;
        }
        cout << endl;
        isFound = 1;
        return;
    }
    int ny, nx;
    for (int i = 0; i <= 7; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        if (isFound == 0)
        {
            if (isInMap(ny, nx) == 1 && mark[ny][nx] == 0)
            {
                path[step + 1].y = ny;
                path[step + 1].x = nx;
                mark[ny][nx] = 1;
                dfs(ny, nx, step + 1);
                mark[ny][nx] = 0;
            }
        }
    }
}

int main()
{
    int caseNum;
    cin >> caseNum;
    for (int caseNo = 1; caseNo <= caseNum; caseNo++)
    {
        cin >> p >> q;
        isFound = false;
        for (int i = 1; i <= p; i++)
        {
            for (int j = 1; j <= q; j++)
            {
                mark[i][j] = 0;
            }
        }
        path[1].y = 1;
        path[1].x = 1;
        mark[1][1] = 1;
        cout << "Scenario #" << caseNo << ":" << endl;
        dfs(1, 1, 1);
        if (!isFound)
        {
            cout << "impossible" << endl
                 << endl;
        }
        else
        {
            cout << endl;
        }
    }
}*/