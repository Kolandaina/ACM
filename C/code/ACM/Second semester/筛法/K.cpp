#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
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
    int n;
    while (cin >> n)
    {
        cout << div(n) << endl;
    }
    return 0;
}