#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 1e5 + 5;
std::vector<int> a(N), b(N);
int n, m;
bool check(int x)
{
    int cnt = 1e18;
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (j < n && a[j + 1] <= a[i] + x)
        {
            ++j;
        }
        cnt = std::min(cnt, a[i] * (i - 1) - b[i - 1] + b[n] - b[j] - (a[i] + x) * (n - j));
    }
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (a[j] < a[i] - x)
        {
            ++j;
        }
        cnt = std::min(cnt, (a[i] - x) * (j - 1) - b[j - 1] + b[n] - b[i] - a[i] * (n - i));
    }
    return cnt <= m;
}
inline void slove()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    std::cout << r << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--)
        slove();
    return 0;
}