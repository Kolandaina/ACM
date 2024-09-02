#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define int long long
const int N = 1e6;
int a[N], cnt = 0;
bool vis[N];
int div()
{
    memset(vis, true, sizeof(vis));
    for (int i = 2; i <= N / i; i++)
    {
        if (vis[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                vis[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (vis[i])
        {
            a[cnt++] = i;
        }
    }
}
signed main()
{
    int n;
    cin >> n;
    int ans;
    div();
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        ans = 0;
        for (int j = 0; j < cnt; j++)
        {
            if (m % a[j] == 0)
            {
                m /= a[j];
                if (m % a[j] == 0)
                {
                    ans = 1;
                    break;
                }
            }
        }
        if (m > 1e6)
        {
            int temp = sqrt(m);
            if (temp * temp == m)
                ans = 1;
        }
        cout << "Case " << i << ": ";
        if (ans == 1)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}