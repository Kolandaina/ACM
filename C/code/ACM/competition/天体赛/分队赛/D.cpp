#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
template <class T1>
std::istream &operator>>(std::istream &cin, std::vector<T1> &a)
{
    for (auto &x : a) cin >> x;
    return cin;
}
template <class T1>
std::ostream &operator<<(std::ostream &cout, const std::vector<T1> &a)
{
    int n = a.size();
    if (!n) return cout;
    cout << a[0];
    for (int i = 1; i < n; i++) cout << ' ' << a[i];
    return cout;
}
inline void slove()
{
    double n;
    double sum;
    std::cin >> n;
    std::vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        sum += a[i];
    }
    sum = sum / n;
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (a[i] - sum) * (a[i] - sum);
    }
    double ans = sqrt(res / n);
    printf("%.5lf\n", ans);
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