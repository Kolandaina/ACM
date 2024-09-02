#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 210;
int n, m;
char f[N][N];
int ans = 0;
bool fun[N][N] = {false};
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int sx, sy, fx, fy;
struct node
{
    int x, y;
    int deep;
} Node;
bool judge(int x, int y)
{
    if (x > 8 || x <= 0 || y > 8 || y <= 0)
    {
        return false;
    }
    if (fun[x][y] == true)
    {
        return false;
    }
    return true;
}
void bfs(int x, int y)
{
    queue<node> q;
    Node.x = x, Node.y = y;
    Node.deep = 0;
    fun[x][y] = true;
    q.push(Node);
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        if (top.x == fx && top.y == fy)
        {
            ans = top.deep;
            return;
        }
        for (int i = 0; i < 8; i++)
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
}
int main()
{
    char s1[3], s2[3];
    while (cin >> s1 >> s2)
    {
        memset(fun, false, sizeof(fun));
        sx = s1[0] - 'a' + 1;
        sy = s1[1] - '0';
        fx = s2[0] - 'a' + 1;
        fy = s2[1] - '0';
        bfs(sx, sy);
        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, ans);
    }
    return 0;
}