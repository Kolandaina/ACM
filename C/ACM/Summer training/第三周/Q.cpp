#include <iostream>
using namespace std;
#define endl "\n"
const int N = 1e5 + 10;
int a[N];
int cnt[22][N];
struct tree
{
    int l, r;
    long long sum;
    long long tag;
} t[22][N << 2];
void pushup(int x, int p)
{
    t[x][p].sum = t[x][p << 1].sum + t[x][p << 1 | 1].sum;
}
void pushdown(int x, int p)
{
    if (t[x][p].tag)
    {
        t[x][p << 1].tag ^= t[x][p].tag;
        t[x][p << 1 | 1].tag ^= t[x][p].tag;
        t[x][p << 1].sum = t[x][p << 1].r - t[x][p << 1].l + 1 - t[x][p << 1].sum;
        t[x][p << 1 | 1].sum = t[x][p << 1 | 1].r - t[x][p << 1 | 1].l + 1 - t[x][p << 1 | 1].sum;
        t[x][p].tag = 0;
    }
}
void build(int x, int p, int l, int r)
{
    t[x][p].l = l, t[x][p].r = r;
    t[x][p].tag = 0;
    if (l == r)
    {
        t[x][p].sum = cnt[x][l];
        return;
    }
    int mid = (l + r) >> 1;
    build(x, p << 1, l, mid);
    build(x, p << 1 | 1, mid + 1, r);
    pushup(x, p);
}
void modifiy(int x, int p, int l, int r)
{
    if (t[x][p].l >= l && t[x][p].r <= r)
    {
        t[x][p].tag ^= 1;
        t[x][p].sum = (t[x][p].r - t[x][p].l + 1) - t[x][p].sum;
        return;
    }
    pushdown(x, p);
    int mid = (t[x][p].l + t[x][p].r) >> 1;
    if (l <= mid)
        modifiy(x, p << 1, l, r);
    if (r > mid)
        modifiy(x, p << 1 | 1, l, r);
    pushup(x, p);
}
int query(int x, int p, int l, int r)
{
    if (t[x][p].l >= l && t[x][p].r <= r)
        return t[x][p].sum;
    pushdown(x, p);
    int mid = (t[x][p].r + t[x][p].l) >> 1;
    long long ans = 0;
    if (l <= mid)
        ans += query(x, p << 1, l, r);
    if (r > mid)
        ans += query(x, p << 1 | 1, l, r);
    return ans;
}
inline void slove()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 21; j++)
        {
            cnt[j][i] = (a[i] >> j) & 1;
        }
    }
    for (int i = 0; i <= 21; i++)
        build(i, 1, 1, n);
    cin >> m;
    while (m--)
    {
        int op, l, r, x;
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r;
            long long ans = 0;
            for (int i = 0; i <= 21; i++)
            {
                ans += query(i, 1, l, r) * (1ll << i);
            }
            cout << ans << endl;
        }
        else
        {
            cin >> l >> r >> x;
            for (int i = 0; i <= 21; i++)
            {
                if ((x >> i) & 1)
                {
                    modifiy(i, 1, l, r);
                }
            }
        }
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}