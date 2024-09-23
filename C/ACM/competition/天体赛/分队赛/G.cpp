#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e6 + 10;
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
int a[N], cnt = 0;
bool vis[N];
void div(int n)
{
    memset(vis, true, sizeof(vis));
    for (int i = 2; i <= n / i; i++)
    {
        if (vis[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                vis[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (vis[i]) a[cnt++] = i;
    }
}
inline void slove()
{
    div(1000000);
    std::vector<int> v;
    for (int i = 0; i < 1000; i++)
    {
        if (a[i] < 1000)
        {
            v.push_back(a[i]);
        }
    }
    int l, r;
    std::cin >> l >> r;
    int n = v.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                if (a[i] >= l && a[i] <= r && a[j] >= l && a[j] <= r &&
                    a[k] >= l && a[k] <= r)
                {
                    if (vis[a[i] * a[j] + a[k]] && vis[a[i] + a[j] * a[k]] &&
                        vis[a[i] * a[k] + a[j]])
                    {
                        ans++;
                    }
                }
            }
        }
    }
    std::cout << ans << endl;
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