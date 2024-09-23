#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node
{
    int x, y;
} f[1000];
inline void slove()
{
    int n;
    cin >> n;
    int a[110], b[110];
    int sum1 = 0, smu2 = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum1 += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        smu2 += b[i];
    }
    if (sum1 != smu2)
    {
        cout << -1 << endl;
    }
    else
    {
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != b[i])
            {
                flag = false;
            }
        }
        if (flag)
        {
            cout << 0 << endl;
        }
        else
        {
            int o = 0, p = 0;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] > b[i])
                {
                    for (int j = 1; j <= a[i] - b[i]; j++)
                    {
                        f[o++].x = i;
                    }
                }
                if (a[i] < b[i])
                {
                    for (int j = 1; j <= b[i] - a[i]; j++)
                    {
                        f[p++].y = i;
                    }
                }
            }
            cout << o << endl;
            for (int i = 0; i <= o - 1; i++)
            {
                cout << f[i].x << " " << f[i].y << endl;
            }
        }
    }
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