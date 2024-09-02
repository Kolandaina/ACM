#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
struct node
{
    int l, r;
    int sum;
} f[N];
void pre(int x)
{
    if (x)
    {
        cout << x << " ";
        pre(f[x].l);
        pre(f[x].r);
    }
    return;
}
void in(int x)
{
    if (x)
    {
        in(f[x].l);
        cout << x << " ";
        in(f[x].r);
    }
    return;
}
void post(int x)
{
    if (x)
    {
        post(f[x].l);
        post(f[x].r);
        cout << x << " ";
    }
    return;
}
inline void slove()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        f[i].sum = i;
        f[i].l = x;
        f[i].r = y;
    }
    pre(1);
    cout << endl;
    in(1);
    cout << endl;
    post(1);
    cout << endl;
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