#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mm = 1e5 + 50, mmax = 0x3f3f3f3f, mod = 998244353;
int num[mm], tt;
int qpow(int a, int b)
{
    int s = 1;
    while (b)
    {
        if (b & 1)
            s *= a;
        b >>= 1;
        a *= a;
        a %= mod;
        s %= mod;
    }
    return s;
}
signed main()
{
    num[0] = 1;
    num[1] = 1;
    for (int i = 2; i < mm; ++i)
    {
        num[i] = num[i - 1] * i;
        num[i] %= mod;
    }
    cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        int s = num[n];
        cout << (s * num[n - 1] % mod * qpow(num[m - 1], mod - 2) % mod * qpow(num[n - m], mod - 2)) % mod << endl;
    }
}
