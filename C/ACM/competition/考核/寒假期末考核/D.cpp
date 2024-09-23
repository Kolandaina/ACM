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
    return cout << a.first << ' ' << a.second;
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
    for (int i = 1; i < n; i++) cout << ' ' << a[i];
    return cout;
}
int ksm(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
inline void slove()
{
    int n;
    std::cin >> n;
    std::set<std::pair<int, int>> s;
    std::vector<std::pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        a[i] = {x, y};
        s.insert({x, y});
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (s.find({a[i].first, a[j].second}) != s.end())
            {
                std::cout << a[i].first << ' ' << a[i].second << ' '
                          << a[j].first << ' ' << a[j].second << endl;
                cnt++;
            }
        }
    }
    std::cout << cnt << endl;
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