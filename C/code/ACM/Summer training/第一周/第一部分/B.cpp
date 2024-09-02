#include <iostream>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e5;
int n, k;
int hh, tt;
int vis[N];
struct node
{
    int x;
    int s;
} q[N];

void bfs()
{
    hh = 1, tt = 0;
    node t;
    t.x = n, t.s = 0;
    vis[n] = 0;
    q[++tt] = t;
    while (hh <= tt)
    {
        t = q[hh++];
        if (t.x == k)
        {
            cout << t.s;
            return;
        }
        node b;
        if (t.x - 1 >= 0 && !vis[t.x - 1])
        {
            vis[t.x - 1] = 1;
            b.x = t.x - 1;
            b.s = t.s + 1;
            q[++tt] = b;
        }
        if (t.x + 1 <= M && !vis[t.x + 1])
        {
            vis[t.x + 1] = 1;
            b.x = t.x + 1;
            b.s = t.s + 1;
            q[++tt] = b;
        }
        if (t.x * 2 <= M && !vis[t.x * 2])
        {
            vis[t.x * 2] = 1;
            b.x = t.x * 2;
            b.s = t.s + 1;
            q[++tt] = b;
        }
    }
}
int main()
{
    cin >> n >> k;
    bfs();
    return 0;
}
