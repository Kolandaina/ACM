#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e6 + 10, p = 998244353;
template <int m>
class modint
{
    using ll = long long;
    using uint = unsigned int;
    using mint = modint;

public:
    modint() : _v(0) {}

    // T =int,long long
    template <typename T>
    modint(T v)
    {
        ll x = (ll)(v % (ll)(umod()));
        if (x < 0)
            x += umod();
        _v = (uint)(x);
    }

    uint val() const { return _v; }

    mint &operator+=(const mint &rhs)
    {
        _v += rhs._v;
        if (_v >= umod())
            _v -= umod();
        return *this;
    }
    mint &operator-=(const mint &rhs)
    {
        _v -= rhs._v;
        if (_v >= umod())
            _v += umod();
        return *this;
    }
    mint &operator*=(const mint &rhs)
    {
        unsigned long long x = _v;
        x *= rhs._v;
        _v = (uint)(x % umod());
        return *this;
    }
    mint &operator/=(const mint &rhs)
    {
        return *this = *this * rhs.inv();
    }
    mint &operator+() { return *this; }
    mint &operator-() { return modint() - *this; }

    mint pow(ll n) const
    {
        mint ans = 1, base = *this;
        while (n)
        {
            if (n & 1)
                ans *= base;
            base *= base;
            n >>= 1;
        }
        return ans;
    }
    mint inv() const
    {
        return pow(umod() - 2);
    }
    friend mint operator+(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) /= rhs;
    }

private:
    uint _v;
    static uint umod() { return m; }
};
using mint = modint<998244353>;
mint fac[N], ifac[N];
void init(int n)
{
    fac[0] = 1;

    for (int i = 1; i <= n; i++)
        fac[i] = mint(i) * fac[i - 1];

    ifac[n] = fac[n].inv();

    for (int i = n - 1; i >= 0; i--)
        ifac[i] = mint(i + 1) * ifac[i + 1];

    return;
}
mint C(int n, int m)
{
    if (n < m || n < 0 || m < 0)
        return (mint)0;

    return fac[n] * ifac[m] * ifac[n - m];
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.tie(0);

    int t, k;
    cin >> t >> k;
    init(k);
    for (int i = 0; i < 10; i++)
    {
        cout << fac[i].val() << " " << ifac[i].val() << endl;
    }
    int res = 0;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        res = res ^ C(n, m).val();
    }
    cout << res;
    return 0;
}