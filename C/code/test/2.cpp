#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
using ld = long double;
struct Point3 {
    ld x, y, z;
    Point3(ld x_ = 0, ld y_ = 0, ld z_ = 0) : x(x_), y(y_), z(z_) {}
    Point3 &operator+=(Point3 p)& {
        return x += p.x, y += p.y, z += p.z, *this;
    }
    Point3 &operator-=(Point3 p)& {
        return x -= p.x, y -= p.y, z -= p.z, *this;
    }
    Point3 &operator*=(Point3 p)& {
        return x *= p.x, y *= p.y, z *= p.z, *this;
    }
    Point3 &operator*=(ld t)& {
        return x *= t, y *= t, z *= t, *this;
    }
    Point3 &operator/=(ld t)& {
        return x /= t, y /= t, z /= t, *this;
    }
    friend Point3 operator+(Point3 a, Point3 b) {
        return a += b;
    }
    friend Point3 operator-(Point3 a, Point3 b) {
        return a -= b;
    }
    friend Point3 operator*(Point3 a, Point3 b) {
        return a *= b;
    }
    friend Point3 operator*(Point3 a, ld b) {
        return a *= b;
    }
    friend Point3 operator*(ld a, Point3 b) {
        return b *= a;
    }
    friend Point3 operator/(Point3 a, ld b) {
        return a /= b;
    }
    friend auto &operator>>(std::istream &is, Point3 &p) {
        return is >> p.x >> p.y >> p.z;
    }
    friend auto &operator<<(std::ostream &os, Point3 p) {
        return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    }
};
struct Line3 {
    Point3 a, b;
};
struct Plane {
    Point3 u, v, w;
};
inline void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::map<std::pair<int, int>, int> mp;
    std::set<std::pair<int, int>> ans;
    mp[ {0, 0}] = 1;
    std::function<void(int, int, int)> dfs = [&](int x, int y, int cnt) {
        if (cnt == n) {
            ans.insert({x, y});
            return;
        }
        int dx = x, dy = y;
        if (s[cnt] == 'R')dx++;
        else if (s[cnt] == 'L') dx--;
        else if (s[cnt] == 'U') dy++;
        else dy--;
        if (mp[ {dx, dy}] == 0) {
            mp[ {dx, dy}] = 1;
            dfs(dx, dy, cnt + 1);
            mp[ {dx, dy}] = -1;
            dfs(x, y, cnt + 1);
            mp[ {dx, dy}] = 0;
        } else if (mp[ {dx, dy}] == 1) {
            dfs(dx, dy, cnt + 1);
        } else dfs(x, y, cnt + 1);
    };
    dfs(0, 0, 0);
    std::cout << ans.size() << endl;
    for (auto &[x, y] : ans) std::cout << x << " " << y << endl;
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    //std:: cin >> t;
    while (t--) solve();
    return 0;
}