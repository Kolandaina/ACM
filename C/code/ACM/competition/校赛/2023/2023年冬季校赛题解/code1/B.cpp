#include <bits/stdc++.h>

const int mod = 1e9 + 7;

long long qmi(long long a, long long b, long long p)
{
    long long res = 1;
    a %= p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    long long res = 0;

    std::vector<int> b(1000001);

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'q') b[i]++;
        b[i] += b[i + 1];
    }

    long long cntq = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'y')
            cntq++;
        else if (s[i] == 'x')
        {
            res = (res + cntq * (cntq - 1) % mod * qmi(2, mod - 2, mod) % mod *
                             b[i] % mod) %
                  mod;
        }
    }

    std::cout << res;

    return 0;
}