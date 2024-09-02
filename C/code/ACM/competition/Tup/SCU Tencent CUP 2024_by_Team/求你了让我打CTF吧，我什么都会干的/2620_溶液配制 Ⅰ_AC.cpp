#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int mod = 1e9 +7;

double a[N];

long long Pow(long long x, int y)
{
    long long res = 1;
    while (y)
    {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

int Ans(int i, int j , int k)
{
    long long res = 1ll;
    res = res * (Pow(2ll, i) - 1) % mod;
    res = res * (Pow(2ll, j) - 1) % mod;
    if (!k) return res;
    res = (res + (Pow(2ll, k) - 1) * Pow(2ll, i + j) % mod) % mod;
    return res;
}

int main()
{
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &a[i]);

    sort(a + 1, a + n + 1);

    while (m--)
    {
        double p; scanf("%lf", &p);
        int beg = lower_bound(a + 1, a + n + 1, p) - a;
        int ed = upper_bound(a + 1, a + n + 1, p) - a;
        int i = beg - 1, k = ed - beg, j = n - ed + 1;
        printf("%d\n", Ans(i, j, k));
    }
    return 0;
}
