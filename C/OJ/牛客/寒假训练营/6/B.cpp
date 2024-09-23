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
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::cin >> a >> b;
    int mindif = INF, idxa = -1, idxb = -1;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        auto it = std::upper_bound(a.begin(), a.end(), b[i]);
        if (it != a.end())
        {
            int t = abs(b[i] - *it);
            if (t < mindif)
            {
                mindif = t;
                idxa = i;
                idxb = it - a.begin();
            }
        }
        if (it != a.begin())
        {
            it--;
            int t = abs(b[i] - *it);
            if (t < mindif)
            {
                mindif = t;
                idxa = i;
                idxb = it - a.begin();
            }
        }
    }
    std::swap(a[idxa], a[idxb]);
    std::cout << a << endl;
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