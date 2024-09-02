#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 5;
int n, k;
struct node
{
    int x, y;
    int ans;
} f[N];
struct node1
{
    bool operator()(const node &s1, const node &s2) const
    {
        return s1.ans > s2.ans;
    }
};
inline void slove()
{
    cin >> n >> k;
    k = -k;
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= n - 2; i++)
    {
        cin >> f[i].x >> f[i].y;
        f[i].ans = f[i].y + f[i].x * k;
    }
    cin >> x >> y;
    sort(f + 1, f + n - 2 + 1, node1());
    cout << f[1].ans << endl;
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