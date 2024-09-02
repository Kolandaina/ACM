#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 32;
int l, r, c;
char f[N][N][N];
bool fun[N][N][N];
struct node
{
    int x, y, z;
    int deep;
} Node;
bool judge(int x, int y, int z)
{
    if (x < 0 || y < 0 || z < 0 || x >= l || y >= r || z >= c)
    {
        return false;
    }
    if (f[x][y][z] == '#' || fun[x][y][z] == true)
    {
        return false;
    }
    return true;
}
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int ans = 0;
void bfs(int x, int y, int z)
{
    queue<node> q;
    Node.x = x, Node.y = y, Node.z = z;
    Node.deep = 0;
    q.push(Node);
    fun[x][y][z] = true;
    while (!q.empty())
    {
        node top = q.front();
        if (f[top.x][top.y][top.z] == 'E')
        {
            ans = top.deep;
            break;
        }
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            Node.x = top.x + dx[i], Node.y = top.y + dy[i], Node.z = top.z + dz[i];
            Node.deep = top.deep + 1;
            if (judge(Node.x, Node.y, Node.z))
            {

                q.push(Node);
                fun[Node.x][Node.y][Node.z] = true;
            }
        }
    }
}
int main()
{
    while (cin >> l >> r >> c && l != 0 && r != 0 && c != 0)
    {
        int sx, sy, sz;
        ans = 0;
        memset(fun, false, sizeof(fun));
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    cin >> f[i][j][k];
                    if (f[i][j][k] == 'S')
                    {
                        sx = i, sy = j, sz = k;
                    }
                }
            }
            getchar();
        }
        bfs(sx, sy, sz);
        if (ans)
        {
            cout << "Escaped in " << ans << " minute(s)." << endl;
        }
        else
        {
            cout << "Trapped!" << endl;
        }
    }
    return 0;
}