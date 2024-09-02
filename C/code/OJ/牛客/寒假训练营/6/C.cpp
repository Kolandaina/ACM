#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
struct node
{
    int a, b, c;
};
std::vector<int> pre(1000);
std::map<int, node> mp;
std::map<int, int> vis;
void init()
{
    pre[0] = 0;
    pre[1] = pre[2] = 1;
    for (int i = 3; i < 1000; i++) pre[i] = pre[i - 1] + pre[i - 2];
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            for (int k = 0; k < 50; k++)
            {
                int x = pre[i] + pre[j] + pre[k];
                if (!vis[x])
                {
                    mp[x].a = pre[i], mp[x].b = pre[j];
                    mp[x].c = pre[k];
                    vis[x]++;
                }
            }
        }
    }
}
inline void slove()
{
    int n;
    std::cin >> n;
    if (vis[n])
        std::cout << mp[n].a << " " << mp[n].b << " " << mp[n].c << endl;
    else
        std::cout << -1 << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    init();
    int t = 1;
    std::cin >> t;
    while (t--) slove();
    return 0;
}