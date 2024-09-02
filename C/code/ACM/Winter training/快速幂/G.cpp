#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1000;
const int mod = 1000000007;
long long n, k;
int p[N][N], ans[N][N], c[N][N], f[N][N];

void mul(int a[N][N], int b[N][N])
{
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            for (int k = 1; k <= 2; k++)
            {
                c[i][j] += a[i][k] * b[k][j] % mod;
            }
        }
    }
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            a[i][j] = c[i][j] % mod;
        }
    }
}
void node(int a[N][N], int k)
{
    for (int i = 1; i <= 10; i++)
        ans[i][i] = 1;
    while (k)
    {
        if (k & 1)
            mul(ans, a);
        mul(a, a);
        k >>= 1;
    }
}
signed main()
{
    cin >> n;
    p[1][1] = 1;
    p[2][1] = 1;
    p[1][2] = 1;
    p[2][2] = 0;
    f[1][1] = 1;
    f[1][2] = 1;
    if (n == 1 || n == 2)
        cout << 1;
    else
    {
        node(p, n - 1);
        mul(ans, f);
        cout << ans[1][1] % mod;
    }
    return 0;
}