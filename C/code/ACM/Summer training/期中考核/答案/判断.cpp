#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int N = 1000010;

int fa[N];
struct Node
{
    int i, j, e;
} node[N];
int v[N];
int idx;
int Find(int x)
{
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y)
{
    int a = Find(x);
    int b = Find(y);
    fa[a] = b;
}
bool cmp(Node a, Node b)
{
    return a.e > b.e;
}
void solve()
{
    int n;
    cin >> n;
    idx = 0;
    for (int i = 0; i <= 1000000; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].i >> node[i].j >> node[i].e;
        v[idx++] = node[i].i;
        v[idx++] = node[i].j;
    }
    sort(v, v + idx);
    int k = unique(v, v + idx) - v;

    for (int i = 1; i <= n; i++)
    {
        int l = lower_bound(v, v + k, node[i].i) - v;
        int r = lower_bound(v, v + k, node[i].j) - v;
        if (node[i].e == 1)
        {
            Union(l, r);
        }
    }
    for (int i = 1; i <= n; i++)
    {

        if (node[i].e == 1)
            continue;
        int l = lower_bound(v, v + k, node[i].i) - v;
        int r = lower_bound(v, v + k, node[i].j) - v;
        if (Find(l) == Find(r))
        {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    cout << "YES"
         << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    //	t=1;

    while (t--)
    {
        solve();
    }
    return 0;
}
