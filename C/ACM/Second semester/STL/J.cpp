#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;
char vis[27] = "abcdefghijklmnopqrstuvwxyz";
int main()
{
    int n, m;
    cin >> n >> m;
    char ans[MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    char a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        for (int j = 0; j < 27; j++)
        {
            if (vis[j] == a)
            {
                vis[j] = b;
                continue;
            }
            if (vis[j] == b)
            {
                vis[j] = a;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << vis[ans[i] - 'a'];
    }
    return 0;
}
