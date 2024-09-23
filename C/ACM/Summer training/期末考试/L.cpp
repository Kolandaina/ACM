#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((a[i] & a[j]) == 0)
            {
                bool flag = true;
                for (int k = i + 1; k < j; ++k)
                {
                    if ((a[k] & a[j]) != 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    ans = max(ans, j - i + 1);
                }
                else
                    break;
            }
            else
                break;
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
    cin >> t;
    while (t--)
        slove();
    return 0;
}