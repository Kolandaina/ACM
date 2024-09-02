#include <bits/stdc++.h>

#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
std::vector<int> f(N, 0);

inline void slove()
{
    int n, q;
    std::cin >> n >> q;
    std::cin >> f[0] >> f[1];
    int a, b;
    std::cin >> a >> b;
    std::vector<int> x(N, 0);
    std::vector<int> p(N, 0);
    for (int i = 0; i < n; i++)std::cin >> x[i];
    for (int i = 2; i <= N; i++)
    {
        f[i] = (1ll * f[i - 1] * b + 1ll * f[i - 2] * a) % mod;
    }
    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        if (l < r)
        {
            p[l] = (p[l] + f[0]) % mod;
            p[l + 1] = (p[l + 1] + f[1]) % mod;
            p[l + 1] = (1ll * p[l + 1] + mod - 1ll * ((1ll * b * f[0]) % mod)) % mod;
            p[r + 1] = (1ll * p[r + 1] + mod - f[r - l + 1]) % mod;
            p[r + 2] = (1ll * p[r + 2] + mod - 1ll * ((1ll * a * f[r - l]) % mod)) % mod;
        } else
        {
            p[l] = (p[l] + f[0]) % mod;
            p[r + 1] = (1LL * p[r + 1] + mod - ((1LL * b * f[0]) % mod)) % mod;
            p[r + 2] = (1LL * p[r + 2] + mod - 1LL * ((1LL * a * f[0]) % mod)) % mod;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 1)
        {
            p[i] = (1ll * p[i] + a * p[i - 2]) % mod;
        }
        if (i)
        {
            p[i] = (1ll * p[i] + b * p[i - 1]) % mod;
        }
        x[i] = (p[i] + x[i]) % mod;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << x[i] << " ";
    }
    std::cout << endl;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}