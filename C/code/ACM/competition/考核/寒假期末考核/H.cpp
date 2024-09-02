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
std::vector<int> a;
int dpp(int l, int r, std::vector<std::vector<int>> &dp)
{
    if (l >= r) return 0;
    if (dp[l][r] == -1)
    {
        dp[l][r] = 0;
        dp[l][r] =
            std::max(dp[l][r], (a[l] + a[l + 1]) % 3 + dpp(l + 2, r, dp));
        dp[l][r] =
            std::max(dp[l][r], (a[r] + a[r - 1]) % 3 + dpp(l, r - 2, dp));
        dp[l][r] =
            std::max(dp[l][r], (a[l] + a[r]) % 3 + dpp(l + 1, r - 1, dp));
    }
    return dp[l][r];
}
inline void slove()
{
    int n;
    std::cin >> n;
    a.resize(n);
    std::cin >> a;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
    std::cout << dpp(0, n - 1, dp);
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
