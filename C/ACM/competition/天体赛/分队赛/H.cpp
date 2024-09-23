#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
int a[N], cnt = 0;
bool vis[N];
void div(int n)
{
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
        if (vis[i]) a[cnt++] = i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    div(n);
    while (k--)
    {
        int m;
        cin >> m;
        cout << a[m - 1] << endl;
    }
    return 0;
}