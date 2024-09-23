#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 200;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
int sx, sy, x1, x2, x3, yy1, y2, y3, ex, ey;
int t1, t2, t3;
char g[N][N];
bool fun[N][N] = {false};
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
struct node
{
    int x, y;
    int deep;
} Node;
int ju(int tx, int ty, int ttx, int tty)
{
    return std::abs(tx - ttx) + std::abs(ty - tty);
}
bool judge(int x, int y)
{
    if (x > n || x <= 0 || y > m || y <= 0)
    {
        return false;
    }
    if (g[x][y] == '#' || fun[x][y] == true)
    {
        return false;
    }
    return true;
}
int BFS(int tx, int ty, int ttx, int tty)
{
    std::queue<node> q;
    std::memset(fun, false, sizeof(fun));
    int ans = 0;
    Node.x = tx;
    Node.y = ty;
    Node.deep = 0;
    q.push(Node);
    fun[tx][ty] = true;
    while (!q.empty())
    {
        node top = q.front();
        if (top.x == ttx && top.y == tty)
        {
            ans = top.deep;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Node.x = top.x + dx[i];
            Node.y = top.y + dy[i];
            Node.deep = top.deep + 1;
            if (judge(Node.x, Node.y))
            {
                q.push(Node);
                fun[Node.x][Node.y] = true;
            }
        }
    }
    return ans;
}
inline void slove()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> g[i][j];
        }
    }
    std::cin >> sx >> sy >> x1 >> yy1 >> x2 >> y2 >> x3 >> y3 >> ex >> ey;
    std::cin >> t1 >> t2 >> t3;
    int bfs1 = BFS(x1, yy1, ex, ey);
    int bfs2 = BFS(x2, y2, ex, ey);
    int bfs3 = BFS(x3, y3, ex, ey);
    if (bfs1 == 0) bfs1 = 1e8;
    if (bfs2 == 0) bfs2 = 1e8;
    if (bfs3 == 0) bfs3 = 1e8;

    // 0-1-2-3-4
    int ans1 = ju(sx, sy, x1, yy1) + ju(x1, yy1, x2, y2) * (t1 + 1) +
               ju(x2, y2, x3, y3) * (t1 + t2 + 1) + bfs3 * (t1 + t2 + t3 + 1);
    // 0-2-1-3-4
    int ans2 = ju(sx, sy, x2, y2) + ju(x2, y2, x1, yy1) * (t2 + 1) +
               ju(x1, yy1, x3, y3) * (t2 + t1 + 1) + bfs3 * (t2 + t1 + t3 + 1);
    // 0-1-3-2-4
    int ans3 = ju(sx, sy, x1, yy1) + ju(x1, yy1, x3, y3) * (t1 + 1) +
               ju(x3, y3, x2, y2) * (t1 + t3 + 1) + bfs2 * (t1 + t3 + t2 + 1);
    // 0-3-2-1-4
    int ans4 = ju(sx, sy, x3, y3) + ju(x3, y3, x2, y2) * (t3 + 1) +
               ju(x2, y2, x1, yy1) * (t3 + t2 + 1) + bfs1 * (t3 + t2 + t1 + 1);
    // 0-2-3-1-4
    int ans5 = ju(sx, sy, x2, y2) + ju(x2, y2, x3, y3) * (t2 + 1) +
               ju(x3, y3, x1, yy1) * (t2 + t3 + 1) + bfs1 * (t2 + t3 + t1 + 1);
    // 0-3-1-2-4
    int ans6 = ju(sx, sy, x3, y3) + ju(x3, y3, x1, yy1) * (t3 + 1) +
               ju(x1, yy1, x2, y2) * (t3 + t1 + 1) + bfs2 * (t3 + t1 + t2 + 1);
    std::cout << std::min({ans1, ans2, ans3, ans4, ans5, ans6}) << '\n';
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}