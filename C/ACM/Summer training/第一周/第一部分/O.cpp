#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int nextx[4] = {0, 0, -1, 1};
int nexty[4] = {1, -1, 0, 0};
char mp[105][105];
int leastturn[105][105];
int k, x1, yy1, x2, y2;
int m, n;
struct node
{
    int x;
    int y;
    int turn;
    int lastturn;
} Node;
bool judge(int x, int y)
{
    if (x < 1 || y < 1 || x > m || y > n)
    {
        return false;
    }
    if (mp[x][y] == '*')
    {
        return false;
    }
    return true;
}
void BFS(int x1, int y1)
{
    queue<node> q;
    Node.x = x1;
    Node.y = y1;
    Node.turn = 0;
    Node.lastturn = -3;
    q.push(Node);
    while (!q.empty())
    {
        node curp = q.front();
        q.pop();
        if (curp.x == x2 && curp.y == y2 && curp.turn <= k)
        {
            cout << "yes" << endl;
            return;
        }
        if (curp.turn > k)
            continue;
        for (int i = 0; i < 4; i++)
        {
            node nextp;
            nextp.x = curp.x + nextx[i];
            nextp.y = curp.y + nexty[i];
            if (judge(nextp.x, nextp.y))
            {
                if (curp.lastturn != i && curp.lastturn != -3)
                {
                    nextp.turn = curp.turn + 1;
                    nextp.lastturn = i;

                    if (nextp.turn > k)
                        continue;
                    if (nextp.turn <= leastturn[nextp.x][nextp.y])
                    {
                        leastturn[nextp.x][nextp.y] = nextp.turn;
                        q.push(nextp);
                    }
                }
                else
                {
                    nextp.turn = curp.turn;
                    nextp.lastturn = i;
                    if (nextp.turn > k)
                        continue;
                    if (nextp.turn <= leastturn[nextp.x][nextp.y])
                    {
                        leastturn[nextp.x][nextp.y] = nextp.turn;
                        q.push(nextp);
                    }
                }
            }
        }
    }
    cout << "no" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> mp[i][j];
                leastturn[i][j] = 0x3f3f3f3f;
            }
        }
        cin >> k >> yy1 >> x1 >> y2 >> x2;
        BFS(x1, yy1);
    }
    return 0;
}