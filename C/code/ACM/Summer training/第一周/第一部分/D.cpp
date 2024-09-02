#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 10;
int n, m, f[N][N];
bool fun[N][N][N][N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
struct node
{
    int sx, sy;
    int px, py;
    int deep;
    bool operator<(const node &a) const
    {
        return a.deep < deep;
    }
};
bool judge(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m || f[x][y] == 1)
        return true;
    return false;
}
void bfs(int x1, int y1, int x2, int y2)
{
    priority_queue<node> q;
    node Node;
    Node.sx = x1, Node.sy = y1, Node.px = x2, Node.py = y2;
    Node.deep = 0;
    fun[x1][y1][x2][y2] = true;
    q.push(Node);
    while (!q.empty())
    {
        node top = q.top();
        q.pop();
        if (f[top.px][top.py] == 3)
        {
            cout << top.deep << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            Node.sx = top.sx + dx[i], Node.sy = top.sy + dy[i];
            if (judge(Node.sx, Node.sy))
                continue;
            Node.px = top.px, Node.py = top.py;
            Node.deep = top.deep;
            if (Node.sx == Node.px && Node.sy == Node.py)
            {
                Node.px = top.px + dx[i], Node.py = top.py + dy[i];
                if (judge(Node.px, Node.py))
                    continue;
                Node.deep++;
            }
            if (!fun[Node.sx][Node.sy][Node.px][Node.py])
            {
                fun[Node.sx][Node.sy][Node.px][Node.py] = true;
                q.push(Node);
            }
        }
    }
    cout << "-1" << endl;
}
void slove()
{
    cin >> n >> m;
    int sx, sy, px, py;
    memset(fun, false, sizeof(fun));
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> f[i][j];
            if (f[i][j] == 2)
                px = i, py = j;
            if (f[i][j] == 4)
                sx = i, sy = j;
        }
    }
    bfs(sx, sy, px, py);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        slove();
    return 0;
}