#include <iostream>
#include <cstring>
using namespace std;
const int N = 1005;
int p[N];
bool fun[N];
int find(int x)
{
    if (x != p[x])
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
int main()
{
    int cnt = 1;
    while (cnt++)
    {
        memset(fun, false, sizeof(fun));
        for (int i = 0; i < N; i++)
        {
            p[i] = i;
        }
        int a, b;
        int flag = 0;
        while (cin >> a >> b)
        {
            if (a == -1 && b == -1)
            {
                return 0;
            }
            if (a == 0 && b == 0)
            {
                break;
            }
            if (find(a) == find(b) || find(b) != b)
            {
                flag = 1;
            }
            if (find(a) != find(b))
            {
                p[find(b)] = find(a);
            }
            fun[a] = fun[b] = true;
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            if (fun[i] && find(i) == i)
            {
                ans++;
            }
        }
        if (ans > 1)
        {
            flag = 1;
        }
        if (flag)
            printf("Case %d is not a tree.\n", cnt - 1);
        else
            printf("Case %d is a tree.\n", cnt - 1);
    }
}