#include <iostream>
using namespace std;
const int N = 1e5;
int p[N], vis[N];
int x[N], y[N];
int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
int main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cin >> x[i] >> y[i];
    }
    char s;
    while (cin >> s)
    {
        if (s == 'O')
        {
            int a;
            cin >> a;
            vis[a] = 1;
            for (int i = 1; i <= n; i++)
            {
                if (a != i && vis[i] == 1 && (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]) <= d * d)
                {
                    p[find(a)] = find(i);
                }
            }
        }
        if (s == 'S')
        {
            int a, b;
            cin >> a >> b;
            if (find(a) != find(b))
            {
                cout << "FAIL" << endl;
            }
            else
            {
                cout << "SUCCESS" << endl;
            }
        }
    }
    return 0;
}