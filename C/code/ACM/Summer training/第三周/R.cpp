#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
int a[N];
string s;
struct tree
{
    int l, r;
    int lx, rx;
} t[N << 2];
void pushup(int p)
{
    t[p].lx = t[p << 1].lx + t[p << 1 | 1].lx - min(t[p << 1].lx, t[p << 1 | 1].rx);
    t[p].rx = t[p << 1].rx + t[p << 1 | 1].rx - min(t[p << 1].lx, t[p << 1 | 1].rx);
}
void bulid(int p, int l, int r)
{
    t[p].l = l;
    t[p].r = r;
    t[p].lx = t[p].rx = 0;
    if (l == r)
    {
        if (s[l] == '(')
            t[p].lx = 1;
        if (s[l] == ')')
            t[p].rx = 1;
        return;
    }
    int mid = (l + r) >> 1;
    bulid(p << 1, l, mid);
    bulid(p << 1 | 1, mid + 1, r);
    pushup(p);
}
tree query(int p, int l, int r)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        return t[p];
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (r <= mid)
        return query(p << 1, l, r);
    if (l > mid)
        return query(p << 1 | 1, l, r);
    tree t1, t2, ans;
    t1 = query(p << 1, l, r);
    t2 = query(p << 1 | 1, l, r);
    ans.lx = t1.lx + t2.lx - min(t1.lx, t2.rx);
    ans.rx = t1.rx + t2.rx - min(t1.lx, t2.rx);
    return ans;
}
inline void slove()
{

    string s1;
    cin >> s1;
    s = " ";
    s += s1;
    int n = s.length();
    bulid(1, 1, n);
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        tree ans = query(1, x, y);
        cout << y - x + 1 - (ans.lx + ans.rx) << endl;
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