#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1010;
const int M = 1e6 + 10;
int a[M], b[M];
int map1[M];
int f[M];
inline void slove()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        map1[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        f[i] = INT_MAX;
    }
    int len = 0;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = len;
        if (map1[b[i]] > f[len])
        {
            f[++len] = map1[b[i]];
        }
        else
        {
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (f[mid] > map1[b[i]])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            f[l] = min(map1[b[i]], f[l]);
        }
    }
    cout << len << endl;
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