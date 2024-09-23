#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5;
int sum[N], ans[N];
struct node
{
    int a, b;
} f[N];
struct node1
{
    bool operator()(const node &a, const node &b)
        const
    {
        return a.a > b.a;
    }
};
inline void slove()
{
    int k, n;
    cin >> k >> n;
    int temp = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].a >> f[i].b;
        sum[f[i].a]++;
    }
    sort(f + 1, f + n + 1, node1());
    for (int i = k; i >= 1; i--)
    {
        if (sum[i] == 0)
        {
            ans[i] = ans[i + 1] + 1;
        }
        else
        {
            for (int j = 1; j <= sum[i]; j++)
            {
                if (ans[i + f[temp].b] > ans[i])
                {
                    ans[i] = ans[i + f[temp].b];
                }
                temp++;
            }
        }
    }
    cout << ans[1] << endl;
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