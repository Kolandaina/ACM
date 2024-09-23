#include <bits/stdc++.h>
template <typename T>
class Modular
{
public:
    static const T MOD = 998244353;
    Modular(T value = 0) : value(value % MOD)
    {
        if (this->value < 0) this->value += MOD;
    }
    Modular operator+(const Modular& other) const
    {
        return Modular((value + other.value) % MOD);
    }
    Modular operator-(const Modular& other) const
    {
        return Modular((value - other.value + MOD) % MOD);
    }
    Modular operator*(const Modular& other) const
    {
        return Modular((value * other.value) % MOD);
    }
    Modular operator/(const Modular& other) const
    {
        return *this * other.inverse();
    }
    Modular& operator=(const T& other)
    {
        value = other % MOD;
        if (value < 0) value += MOD;
        return *this;
    }
    T getValue() const { return value; }

private:
    T value;
    Modular inverse() const
    {
        T t = 0, newt = 1;
        T r = MOD, newr = value;
        while (newr != 0)
        {
            T quotient = r / newr;
            std::swap(t, newt -= quotient * t);
            std::swap(r, newr -= quotient * r);
        }
        if (r > 1) throw std::runtime_error("Value is not invertible");
        if (t < 0) t += MOD;
        return Modular(t);
    }
};
template <typename T>
std::ostream& operator<<(std::ostream& os, const Modular<T>& obj)
{
    return os << obj.getValue();
}
using M = Modular<int>;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int n;
    std::cin >> n;
    M ans = 0;
    int a = 0, b = 0, c = 1, d = 1;
    std::vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        char op;
        std::cin >> op;
        int x;
        std::cin >> x;
        if (op == '+')
        {
            if (x >= 0) a += x;
            if (x < 0) b += x;
        }
        else
        {
            if (x >= 0) c *= x;
            if (x < 0) res.push_back(x);
        }
    }
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