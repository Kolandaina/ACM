#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
template <int m>
class modint
{
    using ll = long long;
    using uint = unsigned int;
    using mint = modint;

public:
    modint() : _v(0) {}
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
string n;
using mint = modint<5>;
int main()
{
    mint ans;
    cin >> n;
    int len = n.length();
    int res;
    if (len == 1)
    {
        res = n[0] - '0';
    }
    else
    {
        res = (n[len - 2] - '0') * 10 + (n[len - 1] - '0');
    }
    for (int i = 1; i <= 4; i++)
    {
        ans += mint(i).pow(res);
    }
    cout << ans.val() << endl;
    return 0;
}
