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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::cin >> a;
    int maxn = *std::max_element(a.begin(), a.end());
    int minn = *std::min_element(a.begin(), a.end());
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == minn)
        {
            x++;
        }
        if (a[i] == maxn)
        {
            y++;
        }
    }
    std::cout << minn << " " << x << endl;
    std::cout << maxn << " " << y << endl;
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