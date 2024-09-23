#include <bits/stdc++.h>

#define int long long

const int mod = 998244353;
int mi[37], ni[37], S[37];
int n, m;

int qmi(int a, int b, int p)
{
    a %= p;
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

signed main()
{
    mi[0] = 1, mi[1] = 2;
    for (int i = 2; i <= 33; i++)
    {
        mi[i] = mi[i - 1] * 2ll;
    }

    ni[1] = 1, S[1] = 1;
    for (int i = 2; i <= 33; i++)
    {
        ni[i] = ni[i - 1] * qmi(2, mod - 2, mod) % mod;
        S[i] = (S[i - 1] + ni[i]) % mod;
    }

    std::cin >> n >> m;
    int k = 0;
    int res = 1;

    for (int i = 1; mi[i] - 1 <= n + m - 1; i++, k++)
    {
        int l = std::max(n, mi[i] - 1);
        int r = std::min(n + m - 1, mi[i + 1] - 2);
        if (l > r)
        {
            continue;
        }
        int len = r - l + 1;
        res = (res * qmi(S[k + 1] * qmi(2, mod - 2, mod), len, mod) % mod);
    }

    std::cout << res;

    return 0;
}
