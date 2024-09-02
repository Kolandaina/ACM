#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5e5 + 10;
int n, m;
int lmin[N], lmax[N], rmin[N], rmax[N];
int a[N], res[N];
vector<int> v[N];
int bfs(int p)
{
    queue<pair<int, int>> q;
    q.push({p, 0});
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        int t1 = t.first, t2 = t.second;
        if (t1 == n)
            return t2; 
        for (int i = 0; i < v[t1].size(); i++)
        {
            int j = v[t1][i];
            q.push({j, t2 + 1});
        }
        v[t1].clear();
    }
    return -1;
}
void change(int l, int r)
{
    if (l >= r)
        return;
    int maxn, minn;
    if (l == 1)
        maxn = lmax[r], minn = lmin[r];
    else
        maxn = rmax[l], minn = rmin[l];
    int p = min(res[maxn], res[minn]);
    int q = max(res[maxn], res[minn]);
    v[p].push_back(q);
    change(l, p), change(q, r);
    return;
}
inline void slove()
{
    cin >> n;
    lmin[0] = rmin[n + 1] = INT_MAX;
    lmax[0] = rmax[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        lmin[i] = min(lmin[i - 1], a[i]);
        lmax[i] = max(lmax[i - 1], a[i]);
        res[a[i]] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        rmax[i] = max(rmax[i + 1], a[i]);
        rmin[i] = min(rmin[i + 1], a[i]);
    }
    change(1, n);
    cout << bfs(1) << endl;
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