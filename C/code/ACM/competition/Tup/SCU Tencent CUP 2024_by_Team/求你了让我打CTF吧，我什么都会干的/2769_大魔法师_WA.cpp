#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

#define gc() getchar()
#define digit(x) (x >= '0' && x <= '9')
int read()
{
    int x = 0, f = 1; char c = gc();
    while (!digit(c)) {if (c == '-') f = -1; c = gc();}
    while (digit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
    return x * f;
}


int d1[N], d2[N], d3[N];
int a1[N], a2[N], a3[N];
int n, m1, m2, m3;

int main()
{
    n = read(); m1 = read(); m2 = read(); m3 = read();
    for (int i = 1; i <= m1; i++)
    {
        int ind = read();
        a1[ind] = max(a1[ind], read());
    }
    for (int i = 2; i <= n; i++) a1[i] = max(a1[i], a1[i - 1]);
    for (int i = 1; i <= m2; i++)
    {
        int ind = read();
        a2[ind] = max(a2[ind], read());
    }
    for (int i = 2; i <= n; i++) a2[i] = max(a2[i], a2[i - 1]);
    for (int i = 1; i <= m3; i++)
    {
        int ind = read();
        a3[ind] = max(a3[ind], read());
    }
    for (int i = 2; i <= n; i++) a3[i] = max(a3[i], a3[i - 1]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            d1[i] = max(d1[i], d1[i - j] + a1[j]);
            d2[i] = max(d2[i], d2[i - j] + a2[j]);
            d3[i] = max(d3[i], d3[i - j] + a3[j]);
        }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; i + j <= n; j++)
        {
            int k = n - i - j;
            ans = max(ans, 1ll * d1[i] * d2[j] * d3[k]);
        }
    printf("%lld\n", ans);
    return 0;
}
