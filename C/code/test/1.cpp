#include <iostream>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;
const int N = 53;
const double INF = 1e18;
const double eps = 1e-8;
#define zero(x) (((x) > 0 ? (x) : -(x)) < eps)
struct point3 {
    double x, y, z;
    point3 operator+(const point3 &o) const {
        return {x + o.x, y + o.y, z + o.z};
    }
    point3 operator-(const point3 &o) const {
        return {x - o.x, y - o.y, z - o.z};
    }
    point3 operator*(const double &o) const {
        return {x * o, y * o, z * o};
    }
    point3 operator/(const double &o) const {
        return {x / o, y / o, z / o};
    }
    bool operator<(const point3 &o) const {
        if (!zero(x - o.x))
            return x < o.x;
        if (!zero(y - o.y))
            return y < o.y;
        return z < o.z;
    }
    bool operator!=(const point3 &o) const {
        return (!zero(x - o.x) || !zero(y - o.y) || !zero(z - o.z));
    }
} a[N];
vector<point3> line;
double vlen(point3 p) {
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}
point3 xmult(point3 u, point3 v) {
    point3 ret;
    ret.x = u.y * v.z - v.y * u.z;
    ret.y = u.z * v.x - u.x * v.z;
    ret.z = u.x * v.y - u.y * v.x;
    return ret;
}
double dmult(point3 u, point3 v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}
point3 projection(point3 p, point3 u) {
    return u * dmult(p, u);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y >> a[i].z;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] != a[j])
                line.push_back(a[i] - a[j]);
    double ans = INF;
    for (int i = 0; i < line.size(); ++i) {
        point3 A = line[i];
        for (int j = i + 1; j < line.size(); ++j) {
            point3 B = line[j];
            if (zero(fabs(dmult(A, B) / vlen(A) / vlen(B)) - 1))
                continue;
            point3 normalVector = xmult(A, B);
            normalVector = normalVector / vlen(normalVector);
            point3 mi = {INF, INF, INF}, ma = {-INF, -INF, -INF};
            for (int k = 0; k < n; ++k) {
                point3 res = projection(a[k], normalVector);
                if (res < mi)
                    mi = res;
                if (ma < res)
                    ma = res;
            }
            ans = min(ans, vlen(mi - ma));
        }
    }
    if (ans == INF || zero(ans))
        ans = 0;
    cout << fixed << setprecision(15) << ans;
    return 0;
}