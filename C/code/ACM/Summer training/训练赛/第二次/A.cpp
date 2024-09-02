#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5;
struct node
{
    int x, y;
} f[N];
inline void slove()
{
    int n, x, m;
    cin >> n >> x >> m;
    int l = x, r = x;
    for (int i = 0; i < m; i++)
    {
        cin >> f[i].x >> f[i].y;
    }
    for (int i = 0; i < m; i++)
    {
        if (f[i].x <= l && l <= f[i].y)
        {
            l = f[i].x;
        }
        if (f[i].x <= r && r <= f[i].y)
        {

            r = f[i].y;
        }
    }
    cout << r - l + 1 << endl;
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