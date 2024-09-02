#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
const int N = 210;
int n, m;
char f[N][N];
int ans = 1e8;
bool fun[N][N] = {false};
struct node
{
    int x, y;
    int deep;
} Node;
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
int Ydeep[N][N], Mdeep[N][N];
bool judge(int x, int y)
{
    if (x >= n || x < 0 || y >= m || y < 0)
    {
        return false;
    }
    if (f[x][y] == '#' || fun[x][y] == true)
    {
        return false;
    }
    return true;
}
void bfsY(int x, int y)
{
    queue<node> q;
    Node.x = x;
    Node.y = y;
    Node.deep = 0;
    q.push(Node);
    fun[x][y] = true;
    while (!q.empty())
    {
        node top = q.front();
        Ydeep[top.x][top.y] = top.deep;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Node.x = top.x + X[i];
            Node.y = top.y + Y[i];
            Node.deep = top.deep + 1;
            if (judge(Node.x, Node.y))
            {
                q.push(Node);
                fun[Node.x][Node.y] = true;
            }
        }
    }
}
void bfsM(int x, int y)
{
    queue<node> q;
    Node.x = x;
    Node.y = y;
    Node.deep = 0;
    q.push(Node);
    fun[x][y] = true;
    while (!q.empty())
    {
        node top = q.front();
        Mdeep[top.x][top.y] = top.deep;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Node.x = top.x + X[i];
            Node.y = top.y + Y[i];
            Node.deep = top.deep + 1;
            if (judge(Node.x, Node.y))
            {
                q.push(Node);
                fun[Node.x][Node.y] = true;
            }
        }
    }
}
int main()
{
    while (cin >> n >> m)
    {
        int tx, ty, mx, my, ans = 1e8;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> f[i][j];
                if (f[i][j] == 'Y')
                {
                    tx = i, ty = j;
                }
                if (f[i][j] == 'M')
                {
                    mx = i, my = j;
                }
            }
        }
        memset(fun, 0, sizeof(fun));
        bfsY(tx, ty);
        memset(fun, 0, sizeof(fun));
        bfsM(mx, my);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (f[i][j] == '@')
                {
                    ans = min(ans, Ydeep[i][j] + Mdeep[i][j]);
                }
            }
        }
        cout << ans * 11 << endl;
    }
    return 0;
}