#include <iostream>
#include <string.h>
using namespace std;
const int N = 1e6;
int a[N];
bool vis[N];
int div(int n)
{
    int cnt = 0;
    memset(vis, true, sizeof(vis));
    for (int i = 2; i <= n / i; i++)
    {
        if (vis[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                vis[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (vis[i])
            a[cnt++] = i;
    }
    return cnt;
}
int main()
{
    div(N);
    int m;
    while (~scanf("%d", &m))
    {
        int t1 = m / 2;
        while (t1 > 0)
        {
            int t2 = m - t1;
            if (vis[t1] && vis[t2])
            {
                cout << t1 << " " << t2 << endl;
                break;
            }
            t1--;
        }
    }
    return 0;
}
