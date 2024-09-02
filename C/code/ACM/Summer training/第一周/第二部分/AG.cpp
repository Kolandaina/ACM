#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int s[maxn], r[maxn];
int find_set(int x)
{
    if (x != s[x])
    {
        int f = s[x];
        s[x] = find_set(s[x]);
        r[x] = (r[x] + r[f]) % 2;
        return s[x];
    }
    return x;
}
int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < maxn; i++)
        {
            s[i] = i;
        }
        memset(r, 0, sizeof(r));
        scanf("%d%d", &n, &m);
        while (m--)
        {
            char str[5];
            int x, y;
            scanf("%s%d%d", str, &x, &y);
            if (str[0] == 'D')
            {
                int fx = find_set(x);
                int fy = find_set(y);
                if (fx != fy)
                {
                    s[fx] = fy;
                    r[fx] = (r[x] + r[y] + 1) % 2;
                }
            }
            else
            {
                int fx = find_set(x);
                int fy = find_set(y);
                if (fx == fy)
                {
                    if ((r[x] + r[y]) % 2 == 0)
                    {
                        printf("In the same gang.\n");
                    }
                    else
                    {
                        printf("In different gangs.\n");
                    }
                }
                else
                {
                    printf("Not sure yet.\n");
                }
            }
        }
    }
    return 0;
}
