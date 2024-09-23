// #include <iostream>
// #include <queue>
// #include <cstring>
// using namespace std;
// const int N = 2000;
// char f[N][N];
// int n, m;
// int Fdeep[N][N];
// int ans = 0;
// bool fun[N][N] = {false};
// int dx[4] = {0, 0, 1, -1};
// int dy[4] = {1, -1, 0, 0};
// struct node
// {
//     int x, y;
//     int deep;
// } Node;
// bool judge(int x, int y)
// {
//     if (x > n || x <= 0 || y > m || y <= 0)
//     {
//         return false;
//     }
//     if (f[x][y] == '#' || fun[x][y] == true)
//     {
//         return false;
//     }
//     return true;
// }
// void bfsF(int x, int y)
// {
//     queue<node> q;
//     Node.x = x, Node.y = y;
//     Node.deep = 0;
//     q.push(Node);
//     fun[x][y] = true;
//     while (!q.empty())
//     {
//         node top = q.front();
//         q.pop();
//         Fdeep[top.x][top.y] = top.deep;
//         for (int i = 0; i < 4; i++)
//         {
//             Node.x = top.x + dx[i];
//             Node.y = top.y + dy[i];
//             Node.deep = top.deep + 1;
//             if (judge(Node.x, Node.y))
//             {
//                 q.push(Node);
//                 fun[Node.x][Node.y] = true;
//             }
//         }
//     }
// }
// void bfsJ(int x, int y)
// {
//     queue<node> q;
//     Node.x = x, Node.y = y;
//     Node.deep = 0;
//     q.push(Node);
//     fun[x][y] = true;
//     while (!q.empty())
//     {
//         node top = q.front();
//         if (top.x == n || top.y == m || top.x == 1 || top.y == 1)
//         {
//             ans = top.deep;
//             break;
//         }
//         q.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             Node.x = top.x + dx[i];
//             Node.y = top.y + dy[i];
//             Node.deep = top.deep + 1;
//             if (judge(Node.x, Node.y) && Node.deep < Fdeep[Node.x][Node.y])
//             {
//                 q.push(Node);
//                 fun[Node.x][Node.y] = true;
//             }
//         }
//     }
// }
// void slove()
// {
//     cin >> n >> m;
//     int jx, jy, fx, fy;
//     ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             cin >> f[i][j];
//             if (f[i][j] == 'J')
//             {
//                 jx = i, jy = j;
//             }
//             if (f[i][j] == 'F')

//             {
//                 fx = i, fy = j;
//             }
//         }
//     }
//     memset(fun, false, sizeof(fun));
//     memset(Fdeep, 0, sizeof(Fdeep));
//     bfsF(fx, fy);
//     memset(fun, false, sizeof(fun));
//     bfsJ(jx, jy);
//     if (ans)
//     {
//         cout << ans + 1 << endl;
//     }
//     else
//     {
//         cout << "IMPOSSIBLE" << endl;
//     }
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         slove();
//     }
//     return 0;
// }
#include <iostream>
#include <cstring>
#include <queue>
#define ll long long
using namespace std;
char map[2000][2000];
int m, n;
int fx[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node
{
    int x, y;
};
queue<node> q;
queue<node> f;
void fact()
{
    int res = 0;
    while (!q.empty())
    {
        res++;
        int t = f.size();
        while (t--)
        {
            node op = f.front();
            f.pop();
            for (int i = 0; i < 4; i++)
            {
                int dx = op.x + fx[i][0];
                int dy = op.y + fx[i][1];
                if (dx < 1 || dy < 1 || dx > m || dy > n || map[dx][dy] == '#' || map[dx][dy] == 'F')
                    continue;
                f.push({dx, dy});
                map[dx][dy] = 'F';
            }
        }
        t = q.size();
        while (t--)
        {
            node op = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int dx = op.x + fx[i][0];
                int dy = op.y + fx[i][1];
                if (dx < 1 || dy < 1 || dx > m || dy > n)
                {
                    printf("%d\n", res);
                    return;
                }
                if (map[dx][dy] != '.')
                    continue;
                q.push({dx, dy});
                map[dx][dy] = 'J';
            }
        }
    }
    printf("IMPOSSIBLE\n");
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%d %d", &m, &n);
        while (!q.empty())
            q.pop();
        while (!f.empty())
            f.pop();
        for (int i = 1; i <= m; i++)
        {
            getchar();
            for (int j = 1; j <= n; j++)
            {
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'J')
                    q.push({i, j});
                if (map[i][j] == 'F')
                    f.push({i, j});
            }
        }
        fact();
    }
    return 0;
}
