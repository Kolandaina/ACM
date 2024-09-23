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

struct Node
{
    int v, w;
    Node(){}
    Node(int a, int b):v(a), w(b){}
};

int d1[N], d2[N], d3[N];
Node a1[N], a2[N], a3[N];
int n, m1, m2, m3;

int main()
{
    n = read(); m1 = read(); m2 = read(); m3 = read();
    for (int i = 1; i <= m1; i++)
    {
        int v = read(), w = read();
        a1[i] = Node(v, w);
    }
    for (int i = 1; i <= m2; i++)
    {
        int v = read(), w = read();
        a2[i] = Node(v, w);
    }
    for (int i = 1; i <= m3; i++)
    {
        int v = read(), w = read();
        a3[i] = Node(v, w);
    }
    for (int i = 1; i <= m1; i++)
        for (int j = n; j >= a1[i].v; j--)
            d1[j] = max(d1[j], d1[j - a1[i].v] + a1[i].w);

    for (int i = 1; i <= m2; i++)
        for (int j = n; j >= a2[i].v; j--)
            d2[j] = max(d2[j], d2[j - a2[i].v] + a2[i].w);

    for (int i = 1; i <= m3; i++)
        for (int j = n; j >= a3[i].v; j--)
            d3[j] = max(d3[j], d3[j - a3[i].v] + a3[i].w);

    for (int i = 2; i <= n; i++) d1[i] = max(d1[i], d1[i - 1]);
    for (int i = 2; i <= n; i++) d2[i] = max(d2[i], d2[i - 1]);
    for (int i = 2; i <= n; i++) d3[i] = max(d3[i], d3[i - 1]);

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
