#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e7 + 10;
int p[N];
int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
struct node
{
    int x, y;
    int z;
} f[N];
struct node1
{
    bool operator()(const node &x, const node &y)
        const
    {
        return x.z > y.z;
    }
};
inline void slove()
{
    map<int, int> mp;
    memset(p, 0, sizeof(p));
    int o = 1;
    int n;
    cin >> n;
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].x >> f[i].y >> f[i].z;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[f[i].x] == 0)
        {
            mp[f[i].x] = o++;
        }
        if (mp[f[i].y] == 0)
        {
            mp[f[i].y] = o++;
        }
        if (f[i].z == 1)
        {
            p[find(mp[f[i].x])] = find(mp[f[i].y]);
        }
        else
        {
            if (find(mp[f[i].x]) == find(mp[f[i].y]))
            {
                flag = false;
            }
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}