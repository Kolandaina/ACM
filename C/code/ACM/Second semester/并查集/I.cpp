#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+100;
int p[N];
int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        p[i] = i;
    }
    int h;
    cin >> h;
    for (int i = 0; i < h; i++)
    {
        int a, b;
        cin >> a >> b;
        p[find(a)] = find(b);
    }
    int sum = 0;
    for (int i = 1; i <= n * m; i++)
    {
        if (i == find(i))
        {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}