#include <bits/stdc++.h>

#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

using namespace std;
int arr[5000900];
int node[5000009];
int in[5000009];
bool vis[5000009];
int mp[5000009];
long long   maxx = 0;
int lcm(long long  a, long long  b)
{
    return a * (b / __gcd(a, b));
}
void dfs(int root)
{
    vis[root] = 1;
    maxx++;
    if (vis[node[root]] != 1)
        dfs(node[root]);
}

long long  ksm(long long a, long long b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b=b>>1;
    }
    return res;
}
inline void slove()
{
    int n;
    std::cin>>n;
    for (int i = 1; i <= n; i++)
    {
        std::cin>>arr[i];
        node[i]=arr[i];
        in[arr[i]]++;
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0) flag = false;
    }
    if (!flag)
    {
        printf("-1\n");
    }
    else
    {
        long long   lm = 1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 1) continue;
            maxx = 0;
            dfs(i);
            if (maxx % 2 == 0) maxx /= 2;
            int mx = maxx;
            for (int j = 2; j * j <=maxx && maxx != 1; j++)
            {
                int cnt = 0;
                while (maxx % j == 0)
                {
                    maxx /= j;
                    cnt++;
                }
                mp[j] = max(cnt, mp[j]);
            }
            if (maxx != 1) mp[maxx] = std::max(mp[maxx], 1ll);
        }
        for(int i=1;i<=n;i++)
        {
            if(mp[i]) lm= lm * ksm(i, mp[i]) % mod;

        }
        printf("%lld\n", lm);
    }
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