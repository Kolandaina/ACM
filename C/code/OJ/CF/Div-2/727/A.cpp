#include <iostream>
using namespace std;
#define int long long
#define endl "\n"
const int N = 100005;
int p[N];
int find(int x)
{
    if (p[x] != x)
    {
        return p[x] = find(p[x]);
    }
    return p[x];
}
inline void slove()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        p[find(x)] = find(y);
    }
    int k;
    cin >> k;
    int a[k];
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    int ans = find(a[0]);
    for (int i = 1; i < k; i++)
    {
        if (find(a[i]) != ans)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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