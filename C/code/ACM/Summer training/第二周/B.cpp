#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const ll N = 5e6 + 10;
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
using mint = modint<100003>;
signed main()
{
    int n, m;
    cin >> m >> n;
    int ans = (mint(m).pow(n).val() - m * mint(m - 1).pow(n - 1)).val();
    cout << ans << endl;
    return 0;
}