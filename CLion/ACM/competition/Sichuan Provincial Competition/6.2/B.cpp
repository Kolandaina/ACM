#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

inline void slove()
{
    double a, b;
    cin >> a >> b;
    double ans1 = 0, ans2 = 0, ans3 = 0;
    double vv = sqrt(6) - sqrt(2);
    ans1 = vv * min(a, b);

    if (a > b)swap(a, b);
    ans2 = a * (2.0 / sqrt(3));
    if (b >= ans2)
    {
        printf("%.11lf\n", ans2);
        return;
    }
    double l = ans1, r = ans2;
    for (int i = 0; i < 10000; i++)
    {
        double mid = (l + r) / 2;
        double xx = b - sqrt(mid * mid - a * a);
        double yy = a - sqrt(mid * mid - b * b);
        if (mid * mid > xx * xx + yy * yy)r = mid;
        else l = mid;
    }
    printf("%.11lf\n", (l + r) / 2);


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