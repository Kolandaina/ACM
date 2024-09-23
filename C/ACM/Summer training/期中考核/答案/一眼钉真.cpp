#include <bits/stdc++.h>
#define inf 1'000'000'000'000'000ll
using namespace std;
using ll = long long;
const int N = 1000005;
ll mod = (long)998244353;
int t;
int n;
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<int> a(n + 1), b(m + 1);
    int x = std::__gcd(n, m);
    std::unordered_map<int, unordered_set<int>> vis;
    std::vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        vis[i % x].insert(a[i]);
    }
    bool h = false;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
        if (vis[i % x].count(b[i]))
        {
            res.emplace_back(i);
        }
    }
    for(int i = 0; i < res.size(); i++)
    {
        printf("%d", res[i]);
        if(i != res.size() - 1) std::cout << ' ';
        else std::cout << '\n';
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}
