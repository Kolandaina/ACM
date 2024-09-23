#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int a[N], cnt = 0;
bool vis[N];
void div()
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
}
int main()
{
    div();
    cout << "21" << endl;
    for (int i = 100; i < 201; i++)
    {
        if (vis[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}