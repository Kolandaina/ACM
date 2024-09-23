#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5000;
int a[N], b[N];
int n, m, ans = 0;
bool flag = false;
inline void slove()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= m; i++)
    {
        vector<int> v;
        flag = false;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] <= b[i])
            {
                v.push_back(a[j]);
            }
        }
        vector<int> w;
        for (int j = 0; j < v.size(); j++)
        {
            if (b[i] == v[j])
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            ans++;
            continue;
        }

        for (int j = 0; j < v.size(); j++)
        {
            for (int k = 0; k < v.size(); k++)
            {
                w.push_back(v[j] + v[k]);
            }
        }
        for (int j = 0; j < w.size(); j++)
        {
            if (w[j] == b[i])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    cout << ans << endl;
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