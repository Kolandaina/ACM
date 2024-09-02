#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
struct node
{
    int x, y;
    int z;
} f[N];
inline void slove()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i].x >> f[i].y;
    }
    int ans = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        if (f[i].x <= 10)
        {
            if (f[i].y >= res)
            {
                res = f[i].y;
                ans = i;
            }
        }
    }
    cout << ans + 1 << endl;
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