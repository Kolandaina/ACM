#include <iostream>
#include <math.h>
#include <memory.h>
using namespace std;
const int N = 1e5;
const int sqr = sqrt(N);
bool vis[N + 1];
int num[N + 1];
void isprim(void)
{
    memset(vis, true, sizeof(vis));
    vis[0] = vis[1] = false;
    for (int i = 2; i <= sqr; i++)
    {
        if (vis[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                vis[j] = false;
            }
        }
    }
    num[0] = num[1] = num[2] = num[3] = num[4] = 0;
    for (int i = 5; i <= N; i++)
    {
        if (vis[i - 2] && vis[i])
            num[i] = num[i - 1] + 1;
        else
            num[i] = num[i - 1];
    }
}

int main()
{
    isprim();
    int n;
    while (scanf("%d", &n) != EOF && n >= 0)
    {
        printf("%d\n", num[n]);
    }
    return 0;
}
