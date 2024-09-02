#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
template <class T1, class T2>
std::istream &operator>>(std::istream &cin, std::pair<T1, T2> &a)
{
    return cin >> a.first >> a.second;
}
template <class T1, class T2>
std::ostream &operator<<(std::ostream &cout, const std::pair<T1, T2> &a)
{
    return cout << a.first << "  " << a.second;
}
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
    for (int i = 1; i <= n; i++) cout << " " << a[i];
    return cout;
}
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::cin >> a;
    int ans = 0, add = 0;
    if (n % 2 == 0)
    {
        std::cout << "YES" << endl;
        return;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i + 1] + add < a[i])
        {
            std::cout << "NO" << endl;
            return;
        }
        if ((i + 1) % 2 == 0)
        {
            add += (a[i + 1] + add - a[i]) / (i + 1);
        }
    }

    std::cout << "YES" << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) slove();
    return 0;
}