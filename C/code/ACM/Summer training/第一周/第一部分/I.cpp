#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
const int maxn = 110;
struct node
{
    int x, y;
    int deep;
} Node;
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
int n, m;
int ans = -1;
char f[maxn][maxn];
bool fun[maxn][maxn] = {false};
bool judge(int x, int y)
{
    if (x >= n || x < 0 || y >= m || y < 0)
    {
        return false;
    }
    if (f[x][y] == '*' || fun[x][y] == true)
    {
        return false;
    }
    return true;
}
void BFS(int x, int y)
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
        if (f[top.x][top.y] == 'T')
        {
            ans = top.deep;
            break;
        }
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
    scanf("%d%d", &n, &m);
    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> f[i][j];
            if (f[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
        }
    }
    fun[sx][sy] = true;
    BFS(sx, sy);
    if (ans >= 0)
    {
        printf("%d\n", ans);
    }
    else
    {
        cout << -1 << '\n';
    }
    return 0;
}
