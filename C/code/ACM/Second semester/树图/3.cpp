#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main()
{
    int n;
    cin >> n;
    int dis[1000];
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int j = 2; j <= n; j++)
    {
        dis[j] = a[1][j];
    }
    dis[0] = 0;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (dis[i] > dis[j] + a[j][i])
            {
                dis[i] = dis[j] + a[j][i];
            }
        }
    }
    cout << dis[n] << endl;
    return 0;
}